#include<stdio.h>
#include<unistd.h>
/*进度条程序*/
int main(){
    char bar[10]={0};
    char per=0;
    while(per<10){
        bar[per]='-';
        printf("%s\r",bar);
        fflush(stdout);
        usleep(100000);
        per++;
    }
    return 0;
}
