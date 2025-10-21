
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    pid_t pid;
    int i;
    int fd;
    
    pid=fork();
    if (pid==0) {
       fd=open("ls_out.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);
       dup2(fd,1);
       close(fd);
       write(1,"stdout je do suboru teraz uz\n",29);
       if (execl("/bin/ls",NULL)<0) {
            printf("Chyba pri execl\n");
        }
    } else {
       printf("Parent\n");
    }
}
