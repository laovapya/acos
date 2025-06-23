#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int id = fork();
    if (id != 0){
        wait(NULL);
        printf("Hello from Grandparent\n");
    }
    else{
        id = fork();
        if (id != 0){
            wait(NULL);
            printf("Hello from parent\n");
        }
        else{
            printf("Hello from child\n");
        }
    }
    
 
    return 0;
}

