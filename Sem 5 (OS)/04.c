/*
 Write a C program to illustrate the concept of an orphan process.
 The parent process creates a child and terminates before the child has finished its task.
 So, the child process becomes an orphan process.
 (Use fork(), sleep(), getpid(), getppid())
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        printf("Parent Process:");
        printf("ID:%d\n\n", getpid());
    } else if (pid == 0) {
        printf("Child Process:");
        printf("ID:%d\n", getpid());
        printf("Parent ID:%d\n\n", getppid());
        sleep(5);
        printf("Child Process:");
        printf("ID:%d\n", getpid());
        printf("Parent ID:%d\n\n", getppid());
    } else {
        printf("Failed to create child process.");
    }
    return 0;
}
