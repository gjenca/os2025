
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
       if (execl("/bin/cat","cat","kapybara.txt",NULL)<0) {
            printf("Chyba pri execl\n");
        }
    } else {
        for (i=0;i<10;i++) {
            printf("Parent\n");
        }
    }
}
