
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {


    char buf[100];
    int read_num;
    int pipefd_w[2];
    int pipefd_r[2];
    int vysledok;
    FILE *fp_w;
    FILE *fp_r;

    if (pipe(pipefd_w)<0) {
        printf("Chyba pri vytvarani pipe\n");
        exit(1);
    }
    if (pipe(pipefd_r)<0) {
        printf("Chyba pri vytvarani pipe\n");
        exit(1);
    }
    if (fork()>0) {
       fp_w=fdopen(pipefd_w[1],"w");
       fp_r=fdopen(pipefd_r[0],"r");
       // write(pipefd_w[1],"2+1\n",4);
       // read_num=read(pipefd_r[0],buf,sizeof(buf)-1);
       // buf[read_num]=0;
       fprintf(fp_w,"2+1\n");
       fflush(fp_w);
       fscanf(fp_r,"%d",&vysledok);
       printf("%d\n",vysledok);
    }
    else {
        dup2(pipefd_w[0],0);
        dup2(pipefd_r[1],1);
        if (execl("/bin/bc",NULL)<0) {
            printf("Chyba pri execl\n");
        }
        
    }
}

    
