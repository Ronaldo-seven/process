#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd=open("./test.txy",O_RDWR);
    if(fd<0){
        perror("open error");
        return -1;
    }
    //\m是刷新缓冲区,仅仅针对标准输出文件才有效
    //对于其他文件,\n的操作仅仅只是进行换行效果
    printf("fd:%d\n",fd);
    fflush(stdout);
    close(fd);
    //close是系统调用的接口,关闭文件的时候不会刷新缓冲区(因为我们所说的这个缓冲区是stdout的缓冲区(用户态的缓冲区))
    return 0;
}
