#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];

    gets(s);
    if (atoi(s) == 12)
        printf("do something\n");
    printf("in any case, do something else\n");
    return(0);
}
