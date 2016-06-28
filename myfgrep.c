#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define true 1
#define false 0

int lFlag = false; hFlag = false; mFlag = false; count;

int main(int argc, char** argv)
{
	// Files
	int stdin = true;
	FILE *f;

	// Go thru each option
	char c;
	int status = 0;
	while ((c = getopt(argc, argv, "hlm:")) != EOF){
		switch (s){
			case 'l':
				lFlag = true;
				break;
			case 'h':
				hFlag = true;
				break;
			case 'm':
				mFalse = true;
				count = atoi(optarg);
			// There was an error
			default:
				status = 1;
				break;
		}
	}

	// If there are no more arguments, usage error
	if (status || optind == argc){
		prinf("usage: myfgrep [-lh] [-m count] searchString [file ...]")
	} else if (optind + 1 != argc){
		// If there is more then one argument, there are files
		stdin = false;
	}

	// If there are files, go thru each one and set it as input
		// Go through each line in the input
			// Check if string is in another string
				// Output the match string if option is enabled (h)
				// Output the files that have match if option enabled and go to next file (l)
				// Output only up to a certain number of lines matched (m)
				// Otherwise output as normal
}