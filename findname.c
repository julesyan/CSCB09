#include <stdio.h>
#include <dirent.h>
#define FALSE 1
#define TRUE 0
    
char searchString[500];

int main (int argc, char** argv)
{
    int i;

    // If there are not enough arguments
    if (argc < 3){
        perror("usage: %s name dir ...", argv[0]);
        return(2);
    } else {
        // Get the search string
        searchString = argv[1];

        // For each directory given
        for (i = 2; i < argc; i++){
            printing(argv[i]);
        }
}

int printing(char *cur)
{
    DIR *dp;
    char path[2000];
    int found = FALSE;
    struct stat s;

    if ((dp = opendir(path)) == NULL){
        perror(path);
        return(1);
    }

    // Read directory
    while ((p = readdir(dp))){
        // If something wrong with file
        if (stat(path, &s)){
            perror(path);
            return(2);
        }
        // If the directory is a directory
        if (S_ISDIR(s.st_mode))
            // Ignore the . and .. cases
            if ((strcmp(p->d_name, ".")) == 0 || (strcmp(p->d_name, "..")) == 0)
                continue;
            // Get the information for the inside
            ///TESTING///
            printf("%s", path);
            printing(p->d_name);                    
    }
    closedir(dp);
    return(found);
}