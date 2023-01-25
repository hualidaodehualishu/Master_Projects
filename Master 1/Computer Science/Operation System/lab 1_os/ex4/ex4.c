#include <stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(void)
{
    int fd;
    char *p ="hello,world\n";
    char *p2 = "ni hao\n";
    fd = open("ex4.txt",O_RDWR|O_CREAT,0644);
    if(fd <0){
        perror("open ex4 error");
        exit(1);
    }
    char a = write(fd,p,strlen(p));
    if(a == -1){
        perror("ex4.txt write error");
    }
    printf("enter anykey continue\n"); 
    getchar();
    int lenth =lseek(fd,0,SEEK_END);
    printf("file size: %d\n",lenth);
    int b =read(fd,p2,strlen(p2));
    if(b == -1){
        perror("ex4.txt read error");
    }
    printf("hi,I've read it!\n");
    close(fd);
    a = unlink("ex4.txt");
    if (a < 0){
        perror("unlink error");
        exit(1);
    }
    return 0;
}
