
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    pid_t pid;
    int fd;
    
    //pid=fork();
    fd=open("kapybara.txt",O_CREAT|O_WRONLY,0666);
    
    if (fd<0) {
        printf("Neviem otvorit subor\n");
        exit(1);
    }
    
    pid=fork();
    if (pid==0) {
        write(fd,"Child kapybara\n",15);
    }
    else if (pid>0) {
        write(fd,"Parent kapybara\n",16);
    }
    else {
        printf("Neviem spustit proces\n");
    }
    close(fd);
}
