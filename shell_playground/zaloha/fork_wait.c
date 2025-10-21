
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    int status;
    pid_t pid;

    pid=fork();
    if (pid==0) {
        printf("Child kapybara\n");
        sleep(1);
        exit(1);
    }
    else if (pid>0) {
        printf("Parent kapybara\n");
        printf("Cakam na ukoncenie child\n");
        wait(&status);
        printf("exit status=%d\n",WEXITSTATUS(status));
    }
    else {
        printf("Neviem spustit proces\n");
    }
}
