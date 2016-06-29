#include <stdio.h>

int main (int argc, char** argv)
{
     char searchString[500];
    char path[2000];
    int i;

    // If there are not enough arguments
    if (argc < 3){
        printf("usage: findname name dir ...")
    } else {
        // Get the search string
        searchString = argv[1];

        // For each directory given

}