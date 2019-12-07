//回顾标准库io接口
#include<string.h>
#include<stdio.h>
int main(){
    FILE *fp=NULL;
    fp=fopen("./tmp.txt","a");
    if(fp==NULL){
        perror("fopen error");
        return -1;
    }
    char buf[1024]="hou xing gang hai shuai a\n";
    fwrite(buf,strlen(buf),1,fp);
    //int fseek (FILE *stream ,long offset ,int whence)
    //对fp文件读写位置从whence开始偏移offset个字节
    //  whence:
    //     SEEK_SET 从文件起始位置开始偏移
    //     SEEK_CUR 从当前读写位置开始偏移
    //     SEEK_END 从文件末尾位置开始偏移
    //返回值; 从文件起始位置到当前跳转位置的偏移量
    fseek(fp,0,SEEK_SET);
    memset(buf,0x00,1024);
    int ret=fread(buf,1024,1,fp);
    printf("ret:%d--buf:[%s]\n",ret,buf);
    fclose(fp);
    return 0;
}
