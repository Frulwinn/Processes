// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE* fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("child process (pid: %d) \n", (int) getpid());
        char child_str[] =  "This is a childstring! \n";
        fwrite(child_str, 1, sizeof(child_str), fp);
    } else {
        printf("parent process (pid: %d) of child %d\n", (int) getpid(), rc);
        char parent_str[] = "This is parent string! \n";
        fwrite(parent_str, 1, sizeof(parent_str), fp);
    }
    fclose(fp);
    return 0;

}
