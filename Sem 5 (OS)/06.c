// File: main_with_exec.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		printf("fork failed");
	}
	else if (pid == 0) {
		
		printf("Child process replacing using exec()\n");
		execl("./01", "01");

		exit(1);
	}
	else {
		// In parent process
		printf("I am parent\n");
	}

	return 0;
}
