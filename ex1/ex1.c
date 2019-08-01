// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    //rc return code
    int rc = fork();
    
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("child process (pid: %d) \n", (int) getpid());
        x = 75;
        printf("x = %d\n", x);
    } else {
        printf("parent process (pid: %d) of child %d\n", (int) getpid(), rc);
        x = 50;
        printf("x = %d\n", x);
    }
    printf("finally x = %d\n", x);
    return 0;
}
