#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define int true 1
#define int false 0

int lFlag = false; hFlag = false; mFlag = false; count; lines = 0; status = 0;

int main(int argc, char** argv)
{
	int i;
	FILE *f;
	char *argv[optind];
	char[500] line;
	extern void int processLine(char *line, char *argv[optind], char *fileName);

	// Go thru each option
	char c;
	while ((c = getopt(argc, argv, "hlm:")) != EOF){
		switch (c){
			case 'l':
				lFlag = true;
				break;
			case 'h':
				hFlag = true;
				break;
			case 'm':
				mFlag = true;
				count = atoi(optarg);
			// There was an error
			default:
				status = 2;
				break;
		}
	}

	// If there are no more arguments, usage error
	if (status || optind == argc){
	}

	// If there are files, go thru each one and set it as input
		// Go through each line in the input
			// Check if string is in another string
				// Output the match string if option is enabled (h)
				// Output the files that have match if option enabled and go to next file (l)
				// Output only up to a certain number of lines matched (m)
				// Otherwise output as normal
	return (status);
}

void int processLine(char *line, char *searchString, char *fileName)
{
	//Determine status
	if (strstr(line, searchString))
		status = 0;
	else 
		status = 1; 

	// Output
	if (status){
		if (hFlag)
			printf("%s\n", line);
		else if (lFlag)
			printf("%s", fileName);
		else {
			printf("%s: %s", fileName, line)
		}
	}
}
