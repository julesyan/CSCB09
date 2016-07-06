#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main ()
{
    int x, i;
    // Create 5 children proccess
    for (i = 0; i < 5; i++){
        x = fork();

        // Error
        if (x == -1){
            perror("fork");
            return(1);
        } else if (x == 0){
            // Comput some of integers 5i through 5i + 4
            return(5*x);
        }
    }

    // Parent now waits

}