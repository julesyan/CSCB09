/*
 * fsh.c - the Feeble SHell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include "fsh.h"
#include "parse.h"
#include "error.h"

int showprompt = 1;
int laststatus = 0;  /* set by anything which runs a command */


int main()
{
    char buf[1000];
    struct parsed_line *p;
    extern void execute(struct parsed_line *p);

    while (1) {
    	if (showprompt)
    	    printf("$ ");
    	if (fgets(buf, sizeof buf, stdin) == NULL)
    	    break;
    	if ((p = parse(buf))) {
    	    execute(p);
    	    freeparse(p);
        }
    }

    return(laststatus);
}


void execute(struct parsed_line *p)
{
    int status;
    extern void execute_one_subcommand(struct parsed_line *p);

    fflush(stdout);
    switch (fork()) {
        case -1:
        	perror("fork");
        	laststatus = 127;
        	break;
        case 0:
        	/* child */
            execute_one_subcommand(p);
        	break;
        default:
        	/* parent */
        	wait(&status);
        	laststatus = status >> 8;
    }
}

struct pipeline * execute_pipe(struct pipeline *pl)
{
    int pipefd[2];

    /* Get a pipe for this cmd */
    if (pipe(pipefd)){
        perror("pipe");
        exit(127);
    }

    /* Executing two cmds, one in each side of pipe */
    switch(fork()){
        case -1:
            perror("fork");
            laststatus = 127;
            break;
        case 0:
            /* child */
            /*  1. Close the input
                2. Have the pipe output as the new output
                3. Clean up the pipe output */
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
            return pl;
        default:
            /* parent */
            /*  1. Close the output
                2. Have pipe output from new input
                3. clean up the pip output */
            close (pipefd[1]);
            dup2(pipefd[0], 0);
            close (pipefd[0]);
            return pl->next;
    }
    return 0;
}

/*
 * execute_one_subcommand():
 * Do file redirections if applicable, then execute the given command from p
 * Does not return, so you want to fork() before calling me.
 */
void execute_one_subcommand(struct parsed_line *p)
{
    struct pipeline *pl;
    extern char **environ;
    struct stat buf;
    char *fileLoc;

    /* Getting the input if new input */
    if (p->inputfile) {
        close(0);
        if (open(p->inputfile, O_RDONLY, 0) < 0) {
            perror(p->inputfile);
            exit(1);
        }
    }

    /* Getting the output if new output */
    if (p->outputfile) {
        close(1);
        if (open(p->outputfile, O_WRONLY|O_CREAT|O_TRUNC, 0666) < 0) {
            perror(p->outputfile);
            exit(1);
        }

        /* If we are writing stderr and stdout to the same file */
        if (p->output_is_double){
            close(2);
            dup2(1, 2);
        }
    }
    if ((pl = p->pl)){
        /* If there is a pipe, execute the pipe */
        if (pl->next){
            pl = execute_pipe(pl);
        }
        
        /* finding the location of the executing cmd */
        fileLoc = pl->argv[0];
        if (!(strchr(fileLoc, '/'))){
            fileLoc = efilenamecons("/bin", pl->argv[0]);
            if (stat(fileLoc, &buf)){
                fileLoc = efilenamecons("/usr/bin", pl->argv[0]);
                if (stat(fileLoc, &buf)){
                    fileLoc = efilenamecons(".", pl->argv[0]);
                    if (stat(fileLoc, &buf)){
                        fprintf(stderr, "%s: Command not found\n", 
                            pl->argv[0]);
                        exit(1);
                    }
                }
            }
        }

        /* executing the command */
        if ((laststatus = execve(fileLoc, pl->argv, environ))){
            perror(fileLoc);
            exit(1);
        }
    }
    exit(0);
}
