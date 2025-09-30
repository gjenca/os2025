
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {


    char buf[100];
    int read_num;
    int pipefd_w[2];
    int pipefd_r[2];

    if (pipe(pipefd_w)<0) {
        printf("Chyba pri vytvarani pipe\n");
        exit(1);
    }
    if (pipe(pipefd_r)<0) {
        printf("Chyba pri vytvarani pipe\n");
        exit(1);
    }
    if (fork()>0) {
       write(pipefd_w[1],"2+1\n",4);
       read_num=read(pipefd_r[0],buf,sizeof(buf)-1);
       buf[read_num]=0;
       printf("%s",buf);
    }
    else {
        dup2(pipefd_w[0],0);
        dup2(pipefd_r[1],1);
        if (execl("/bin/bc",NULL)<0) {
            printf("Chyba pri execl\n");
        }
        
    }
}

    
