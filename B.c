Q.2) Write a C program to create an unnamed pipe. The child process will write the following three messages to the pipe, and the parent process will display them. Message1 = "Hello World" Message2 = "Hello SPPU" Message3 = "Linux is Funny"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == 0) {       
        close(pipe_fd[0]); 
        write(pipe_fd[1], "Hello World\n", strlen("Hello World\n"));
        write(pipe_fd[1], "Hello SPPU\n", strlen("Hello SPPU\n"));
        write(pipe_fd[1], "Linux is Funny\n", strlen("Linux is Funny\n"));
        close(pipe_fd[1]); 
    } else if (pid > 0) {       
        close(pipe_fd[1]);
        wait(NULL); 
        while (read(pipe_fd[0], buffer, sizeof(buffer)) > 0) {
            printf("%s", buffer);  
        }
        close(pipe_fd[0]);
    } else {
        perror("fork");
    }

    return 0;
}

Output:
Hello World
Hello SPPU
Linux is Funny