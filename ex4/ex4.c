// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here 
    int rc = fork();
    int status;

    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        printf("Child process! \n");

        //execl("/bin/ls", "ls", "-l", (char*)NULL);
        //char *args[] = {"ls", "-l", NULL};
        //execv("/lbin/ls", args);
        //execlp("ls", "ls", "-l", (char*)NULL);

        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
    } else {
        wait(NULL);
        }
    return 0;   

}
