#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(){
    //设置调用进程的文件创建权限掩码
    umask(0);
   // int open(const char *pathname, int flags, mode_t mode);
   // pathname  文件名称
   // flags  选型参数
   //     必选其一:
   //       O_RDONLY  只读
   //       O_WRONLY  只写
   //       O_RDWR    读写
   //     可选项:
   //       O_CREAT   文件存在则打开, 不存在则创建
   //       O_TRUNC   清空原有内容
   //       O_APPEND  追加
   //mode: 权限
   //返回值: 成功返回一个文件描述符
   //        失败返回-1
   int fd=open("./test.txt", O_RDWR | O_CREAT | O_APPEND , 0664);
   if(fd < 0){
    perror("open error");
    return -1;
   }
   char *ptr="houxingganghaoshuaia\n";
    // ssize_t write(int fd, const void *buf, size_t count);
    //fd: 文件描述符(系统调用接口的操作句柄)
    //buf  要写入的数据
    //count   要写入的数据长度
    //返回值: 实际写入的数据长度(字节 )  失败返回-1
    int ret=write(fd, ptr, strlen(ptr));
    if(ret<0){
        printf("写入错误");
    }
    // off_t lseek(int fd, off_t offset, int whence);
    //fd: 文件路径
    //offset:偏移量
    //whence: 偏移起始位置:
    //        SEEK_SET  文件起始位置
    //        SEEK_CUR  当前读写位置
    //        SEEK_END  文件末尾位置
    //返回值: 从文件起始位置到当前读写位置的偏移量  失败返回-1;
    lseek(fd,0,SEEK_SET);
//ssize_t read(int fd, void *buf, size_t count);
//  fd  文件的路径 
//  buf 内存的首地址, 用于存储读取的数据
//  count 要读取的数据长度
//  返回值: 实际读取的数据长度(字节)  失败返回-1;
    char buf[1024]={0};
    ret=read(fd, buf, 1023);
    if(ret<0){
        perror("read error");
        return -1;
    }
    printf("read buf:%d---[%s]\n",ret,buf);
    close(fd);
    return 0;
}
