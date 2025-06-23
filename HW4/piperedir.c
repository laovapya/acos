#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int fd[2];
    pipe(fd);

    pid_t pid1, pid2;
    int status1, status2;

    switch (pid1 = fork()) {
       case -1: {
           return -1;
       }
       case 0: {
            dup2(fd[1], STDOUT_FILENO);  
            close(fd[0]);
            close(fd[1]);
            execvp(argv[1], &argv[3]);
       }
       default: {
            break;
       }
    }

    switch (pid2 = fork()) {
       case -1: {
           return -1;
       }
       case 0: {
            dup2(fd[0], STDIN_FILENO);   
            close(fd[1]);
            close(fd[0]);
            execvp(argv[2], &argv[3]);
       }
       default: {
            break;
       }
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);

    if (WIFEXITED(status1))
        printf("%s exit code: %d\n", argv[1], WEXITSTATUS(status1));
    if (WIFEXITED(status2))
        printf("%s exit code: %d\n", argv[2], WEXITSTATUS(status2));

    return 0;
}
