#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {

    char* const infile = argv[1];
    char* const outfile = argv[2];

    switch (fork()) {
       case -1: {
           perror("fork");
           return -1;
       }
       case 0: {
            int fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
            if (fd_out == -1) {
                perror("open outfile");
                exit(1);
            }

            int fd_in = open(infile, O_RDONLY);
            if (fd_in == -1) {
                perror("open infile");
                close(fd_out);
                exit(1);
            }

            if (dup2(fd_out, STDOUT_FILENO) == -1) {
                perror("dup2 stdout");
                close(fd_out);
                close(fd_in);
                exit(1);
            }

            if (dup2(fd_in, STDIN_FILENO) == -1) {
                perror("dup2 stdin");
                close(fd_out);
                close(fd_in);
                exit(1);
            }
           close(fd_out);
           close(fd_in);

          
           execvp(argv[3], &argv[3]);
           perror("execvp"); 
           exit(1);
           
       }
       default: {
            int wstatus;
            if (wait(&wstatus) == -1) {
                perror("wait");
                return 1;
            }
            if (WIFEXITED(wstatus)) {
                int code = WEXITSTATUS(wstatus);
                printf("Exit code: %d\n", code);
            }
            break;
       }
    }
    return 0;
}
