#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DUNGEONSIZE 10
char *map[DUNGEONSIZE][DUNGEONSIZE];

void printMap(){
    for (i = 0; i < DUNGEONSIZE; i++){
        for (j = 0; j < DUNGEONSIZE; j++){
            printf("%s\t", map[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    FILE *f;
    char line[500];
    char *t;
    int i;
    int j;

    if (argc != 2){
        fprintf(stderr, "usage: %s mapfile", argv[0]);
        return(1);
    }

    // Read in the file  
    if ((f = fopen(argv[1], "r")) == NULL){
        perror(argv[1]);
        return(1);
    } 
    i = 0;
    while (fgets(line, 500, f) || i < DUNGEONSIZE){
        // Getting tokens
        j = 0;
        for (t = strtok(line, " \t\n"); j < DUNGEONSIZE; t = strtok(NULL, " \t\n")){
            // If the token is null
            if (t == NULL){
                t = "pass";
            }
            if ((map[i][j] = malloc(strlen(t) + 1)) == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            strcpy(map[i][j], t);
            j++;
        }
        i++;
        memset(line, 0, sizeof line);
    }
    fclose(f);

    /*
    NOTES:
        - When asking user for input is: "You are at: <room>\n"
        - When getting input only looks at first character even if there are 
            other characters there (e.g. exit becomes e) DOES NOT TAKE IN 
            MULTIPLE CMDS AT ONCE (i.e. esn)
        - if room=pass then goes to next available
        - if is reach the edge go back to beginning (i.e. top and left)
        - continuous input
        - if not recognized input then "Type n, w, e, s, or m.\n"

    */    


}