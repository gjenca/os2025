
#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid,pid2;

    pid=fork();
    if (pid==0) {
        printf("Child kapybara\n");
    }
    else if (pid>0) {
        printf("Parent kapybara\n");
    }
    else {
        printf("Neviem spustit proces\n");
    }
}
