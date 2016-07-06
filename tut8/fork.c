#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void childProcess(int i){ 
    int sum, j;
    // Sums up from 5i to 5i+4
    for (sum = j = 0; j < 5, j++){
        sum += (5*i) + j;
    }
    exit(sum);
}

int main ()
{
    int sum, x, i;
    // Create 5 children proccess
    for (i = 0; i < 5; i++){
        x = fork();

        // Error
        if (x == -1){
            perror("fork");
            return(1);
        } else if (x == 0){
            // Comput some of integers 5i through 5i + 4
            childProcess(i);
        }
    }

    // Parent (for each parent created)
    for (sum = i = 0; i < 5; i++){
        // Waits for child
        wait(&status);

        // sums the total exit statuses
        // ***WHAT IS >> 8***
        sum += (status >> 8);
    }
    // print and end
    printf("%d\n", sum);
    return(0);
}