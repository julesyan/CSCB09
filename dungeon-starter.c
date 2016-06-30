#define DUNGEONSIZE 10
char *map[DUNGEONSIZE][DUNGEONSIZE];



            if ((map[i][j] = malloc(strlen(t) + 1)) == NULL) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            strcpy(map[i][j], t);
