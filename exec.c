/*exec函数组的使用*/
//谁调用就对谁进行程序替换
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
   
   printf("hou xing gang hao shuai a \n");
   //execl("/bin/ls","ls","-l",NULL);
   char *argv[32];
   argv[0]="MYENV=1000";
   argv[1]=NULL;
   execve
   execlp("ls","ls","-l",NULL);
   printf("侯兴刚好帅啊\n");
return 0;
}
