#include <stdio.h>
#include <unistd.h>
#define true 1
#define false 0

    int main(int argc, char** argv)
    {
		// Go thru each option
		int optionL = false;
		int optionH = false;
		int optionM = false;
		char c;
		while ((c = getopt(argc, argv, "hlm::")) != -1){
			if (c == 'h'){
				printf("option h");
				optionH = true;
			} else if (c == 'l'){
				printf("option l");
				optionL = true;
			} else if (c == 'm'){
				printf("option m");
				optionM = true;
		}

        // Check if string is in another string
            // Output the match string if option is enabled
            // Output the files that have match if option enabled
    }