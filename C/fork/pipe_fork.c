
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {


    char buf[100];
    int pipefd[2];
    int read_num;
    int x;

    if (pipe(pipefd)<0) {
        printf("Chyba pri vytvarani pipe\n");
        exit(1);
    }
    if (fork()==0) {
        close(pipefd[0]);
        for (x=0;x<100;x++) {
            write(pipefd[1],"Kapybara ",9);
        }
        exit(0);
    }
    else {
        close(pipefd[1]);
        while (1) {
            read_num=read(pipefd[0],buf,sizeof(buf)-1);
            if (read_num==0) {
                break;
            }
            if (read_num<0) {
                printf("Chyba pri read\n");
                exit(1);
            }
            buf[read_num+1]=0;
            printf("Precital %s\n",buf);
        }
    }
}

    
