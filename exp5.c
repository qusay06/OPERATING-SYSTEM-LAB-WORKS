#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;
    char message[] = "Hello from Child Process";
    char buffer[100];

    if (pipe(fd) < 0) {
        printf("Pipe Creation Failed\n");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
        exit(1);
    } else if (pid == 0) {
        close(fd[0]); // Close reading end
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
        exit(0);
    } else {
        wait(NULL);
        close(fd[1]); // Close writing end
        read(fd[0], buffer, sizeof(buffer));
        printf("Message received from child: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}