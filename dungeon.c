#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DUNGEONSIZE 10
#define TRUE 0
#define FALSE 1
#define DEFAULT "pass"
char *map[DUNGEONSIZE][DUNGEONSIZE];
int w = 0, h = 0;

void printMap(){
    int i = 0, j = 0;
    for (; i < DUNGEONSIZE; i++){
        for (; j < DUNGEONSIZE; j++)
            printf("%s\t", map[j][i]);
        printf("\n");
    }
}

int isDefault()
{
    // Check outside of bounds and return if in default room
    if (h < 0) 
        h = DUNGEONSIZE - 1;
    else if (h == DUNGEONSIZE)
        h = 0;
    if (w < 0)
        w = DUNGEONSIZE - 1;
    else if (w == DUNGEONSIZE)
        w = 0;
    if (strcmp(map[w][h], DEFAULT))
        return FALSE;
    return TRUE;
}


int main(int argc, char **argv)
{
    FILE *f;
    char line[500], *t, c;

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
            if (t == NULL)
                t = DEFAULT;
            if ((map[w][h] = malloc(strlen(t) + 1)) == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            strcpy(map[w][h], t);
            w++;
        }
        h++;
        memset(line, 0, sizeof line);
    }
    fclose(f);

    // Getting input from user to move around the map   
    w = 0; h = 0;
    printf("You are at room: %s\n", map[w][h]);
    while (fgets(line, 500, stdin)){
        c = line[0];
        switch(c){
            case 'n':
                for (h--; isDefault() == TRUE; h--) {}
                break;
            case 'e':
                for (w++; isDefault() == TRUE; w++) {}
                break;
            case 's':
                for (h++; isDefault() == TRUE; h++) {}
                break;
            case 'w':
                for (w--; isDefault() == TRUE; w--) {}
                break;
            case 'm':
                printMap();
                break;
            default:
                printf("Type n, w, e, s, or m\n");
                break;
        }
        printf("You are at room: %s\n", map[w][h]);
    }
    return(0);
}