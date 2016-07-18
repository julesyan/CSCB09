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

int showprompt = 0;
int laststatus = 0;  /* set by anything which runs a command */


int main(int argc, char **argv)
{
    char buf[1000];
    struct parsed_line *p;
    extern void execute(struct parsed_line *p);
    char c;
    int vFlag = 0, cFlag = 0;
    FILE *fp;

    /* Go thru each option */
    while ((c = getopt(argc, argv, "vic:")) != EOF){
        switch(c){
            case 'v':
                vFlag = 1;
                break;
            case 'i':
                showprompt = 1;
                break;
            case 'c':
                cFlag = 1;
                strcpy(buf, optarg);
                break; 
        }
    }

    /* If there is a file name, change stdin, unless option c is present, 
     * then give usage error */
    fp = stdin;
    if (optind != argc){
        if (cFlag){
            fprintf(stderr, "usage: %s [-i] [-v] [{file | -c command}]\n",
                argv[0]);
            return(1);
        }
        if ((fp = fopen(argv[optind], "r")) == NULL){
            perror(argv[optind]);
            return(1);
        }
    }

    while (1) {
    	if ((showprompt | isatty(fileno(fp))) && !cFlag)
    	    printf("$ ");
        if (!cFlag && fgets(buf, sizeof buf, fp) == NULL)
    	    break;
    	if ((p = parse(buf))) {
            if (vFlag && !cFlag)
                printf("%s", buf);
    	    execute(p);
    	    freeparse(p);
        }
        if (cFlag)
            break;
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

struct pipeline * execute_pipe(struct pipeline *pl, int isdouble)
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
            /* child - left side*/
            /*  1. Close the input (use stdin)
                2. Have the pipe output as the new output
                3. Clean up the pipe output */
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);

            /* If also redirecting error input */
            if (isdouble){
                close(2);
                dup2(1, 2);
            }
            return pl;
        default:
            /* parent - right side*/
            /*  1. Close the output (use stdout)
                2. Have pipe output from new input
                3. clean up the pipe input */
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
            pl = execute_pipe(pl, pl->next->isdouble);
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
