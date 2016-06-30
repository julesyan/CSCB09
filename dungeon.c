#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DUNGEONSIZE 10
#define TRUE 0
#define FALSE 1
#define DEFAULT "pass"
char *map[DUNGEONSIZE][DUNGEONSIZE];
int w = 0; h = 0;

void printMap(){
    int i = 0; j = 0;
    for (i = 0; i < DUNGEONSIZE; i++){
        for (j = 0; j < DUNGEONSIZE; j++){
            printf("%s\t", map[i][j]);
        }
        printf("\n");
    }
}

int isDefault()
{
    // Check outside of bounds
    if (h < 0)
        h = DUNGEONSIZE - 1;
    else if (h = DUNGEONSIZE)
        h = 0;
    if (w < 0)
        w = DUNGEONSIZE - 1;
    else if (w = DUNGEONSIZE)
        w = 0;

    if (map[x][y] == DEFAULT)
        return TRUE;
    return FALSE;
}


int main(int argc, char **argv)
{
    FILE *f;
    char line[500]; *t; 
    int counter;

    if (argc != 2){
        fprintf(stderr, "usage: %s mapfile", argv[0]);
        return(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL){
        perror(argv[1]);
        return(1);
    } 
    // Getting tokens and filling in the entire map
    while (fgets(line, 500, f) || h < DUNGEONSIZE){
        w = 0;
        for (t = strtok(line, " \t\n"); w < DUNGEONSIZE; 
            t = strtok(NULL, " \t\n")){
            // If no token present, set to default, otherwise add it in to map
            if (t == NULL){
                t = DEFAULT;
            }
            if ((map[i][j] = malloc(strlen(t) + 1)) == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            strcpy(map[i][j], t);
            w++;
        }
        h++;
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
    w = 0; h = 0;
    printf("You are at room: %s\n", map[w, h]);
    while (fgets(line, 500, stdin)){
        t = line[0];
        switch(c){
            case 'n':
                for (h--; isDefault(); h--)
                break;
            case 'e':
                for (w++; isDefault(); w++)
                break;
            case 's':
                for (h++; isDefault(); h++)
                break;
            case 'w':
                for (w--; isDefault(); w--)
                break;
            case 'm':
                printMap();
                break;
            default:
                printf("\nType n, w, e, s, or m\n")
                break;
        }
        printf("You are at room: %s\n", map[w, h]);
    }
}