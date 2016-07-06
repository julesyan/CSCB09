#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    struct stat statbuf;

    if (lstat(".", &statbuf)){
        perror(".");
        return(1);
    }

    
}