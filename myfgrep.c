#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define FALSE 1
#define TRUE 0

int lFlag = FALSE, hFlag = FALSE, mFlag = FALSE, count, lines = 0, status = 0,
	found = FALSE, lotsOfFiles = FALSE;

int main(int argc, char **argv)
{
	int i;
	FILE *f;
	char line[500];
	extern void processLine(char *line, char *searchString, char *fileName);

	// Go thru each option
	char c;
	while ((c = getopt(argc, argv, "hlm:")) != EOF){
		switch (c){
			case 'l':
				lFlag = TRUE;
				break;
			case 'h':
				hFlag = TRUE;
				break;
			case 'm':
				mFlag = TRUE;
				count = atoi(optarg);
			// There was an error
			default:
				status = 2;
				break;
		}
	}

	// If there are no more arguments, usage error
	if (status || optind == argc){
		printf("usage: myfgrep [-lh] [-m count] searchString [file ...]\n");
	} else {	
		// If no files, standard input
		if (argc == optind + 1){
			while (fgets(line, 500, stdin) != NULL && 
				(mFlag == FALSE || lines < count)){
				processLine(line, argv[optind], "stdin");
			}
		} else {
			if (argc > optind + 2) { lotsOfFiles = TRUE; }
			// If there are no more arguments process standard input
			for (i = optind + 1; i < argc && status != 2; i++){
				// If standard input
				if (!(strcmp(argv[i], "-"))){
					while (fgets(line, 500, stdin) != NULL && 
						(mFlag == FALSE && lines < count))
						processLine(line, argv[optind], "stdin");
				} else {
					// Open file 
					f = fopen(argv[i], "r");
					if (f == NULL){
						perror("Error opening file");
						status = 2;
					}
					// Process each line
					while (fgets(line, 500, f) != NULL  && 
						(mFlag == FALSE && lines < count))
						processLine(line, argv[optind], argv[i]);
					fclose(f);
				}			
			}
		}
	}
	if (status != FALSE && status != TRUE)
		return status;
	else
		return found;
}

void processLine(char *line, char *searchString, char *fileName)
{
	//Determine status
	if (strstr(line, searchString)){
		found = TRUE;
		if (hFlag == TRUE || lotsOfFiles == FALSE)
			printf("%s", line);
		else if (lFlag == TRUE)
			printf("%s\n", fileName);
		else {
			printf("%s: %s", fileName, line);
		}
		if (mFlag == TRUE) { lines ++; }
	}
}
