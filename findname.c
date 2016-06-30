#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#define FALSE 1
#define TRUE 0
    
const char *searchString;

int printFound(char *cur)
{
    DIR *dp;
    struct dirent *p;
    struct stat statbuf;
    char path[2000];
    int found = FALSE;

    // Check directory is ok
    if ((dp = opendir(cur)) == NULL){
        perror(cur);
        return(2);
    }

    // Read directory
    while ((p = readdir(dp))){
        // Get the path of the current file/directory
        strcpy(path, cur);
        strcat(path, "/");
        strcat(path, p->d_name);

        // If something wrong with file
        if (stat(path, &statbuf)){
            perror(p->d_name);
            return(2);
        }

        // If the directory is a directory
        if ((S_ISDIR(statbuf.st_mode))){
            // Ignore the . and .. cases
            if ((strcmp(p->d_name, ".")) == 0 || (strcmp(p->d_name, "..")) == 0)
                continue;
            found = printFound(path); 
        } else {
            // If the names match
            if (strcmp(p->d_name, searchString) == 0){
                printf("%s\n", path);
                found = TRUE;
            }
        }              
    }
    closedir(dp);
    return(found);
}

int main (int argc, char** argv)
{
    int i;
    int found = FALSE;

    if (argc < 3){
        fprintf(stderr, "usage: %s name dir ...", argv[0]);
        return(2);
    } else {
        // Get the search string
        searchString = argv[1];

        // For each directory given
        for (i = 2; i < argc; i++){
            // If error happened, exit
            found = printFound(argv[i]);
            if (found != FALSE && found != TRUE)
                return(2);
        }
    }
    return (found);
}