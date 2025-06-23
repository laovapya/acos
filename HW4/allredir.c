#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char* const command = argv[1];
    char* const out = argv[2];
    char* const in = argv[3];
    switch (fork()) {
       case -1: {
           return -1;
       }
       case 0: {
           int fd1 = open(out, O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
           int fd2 = open(in, O_CREAT|O_RDONLY, S_IRUSR|S_IWUSR);
           close(STDOUT_FILENO);
           close(STDIN_FILENO);

           dup2(fd1, STDOUT_FILENO);
           dup2(fd2, STDIN_FILENO);
           execlp(command, "pineapple", NULL);
           break;
       }
       default: 
       {

            int wstatus;
            wait(&wstatus);
            if (WIFEXITED(wstatus)) {
                int code = WEXITSTATUS(wstatus);
                    printf("Exit code: %d\n", code);
            } 
            break;
       }
    }
    return 0;
}
