#include <stdio.h>
#include <string.h>
#define DUNGEONSIZE 10
char *map[DUNGEONSIZE][DUNGEONSIZE];


int main(int argc, char **argv)
{
    if (argc != 2){
        fprintf(stderr, "usage: %s file", argv[0]);
        return(1);
    }

    
            if ((map[i][j] = malloc(strlen(t) + 1)) == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            strcpy(map[i][j], t);

}