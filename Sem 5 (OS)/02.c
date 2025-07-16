#include <stdio.h>
#include <sys/types.h>    // used to provide pid
#include <unistd.h>       // will remove warnings

void main()
{
    pid_t pid;
    int retnice;
    pid = fork();

    if (pid == 0)
    {
        retnice = nice(-4);
        printf("Child gets higher CPU priority %d\n", retnice);
        sleep(5);
    }
    else
    {
        retnice = nice(6);
        printf("Parent gets lower CPU priority %d\n", retnice);
        sleep(5);
    }
}
