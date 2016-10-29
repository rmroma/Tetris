//Asi Belachow- 015803919
//Linux ubuntu 13.04
#include <stdio.h>
#include <termios.h>            
#include <unistd.h>
#include <sys/fcntl.h>
#include <signal.h>

int fd[2];
char s1;
void sig_read(int x)
{

 int count;
 char r;
 count=read(fd[0],&r,1);
 printf("read %d=c",r);
 signal(SIGUSR1,sig_read);

 
}
void sig_write(int x)
{
 printf(".");
 write(fd[1],&s1,1);
 signal(SIGUSR2,sig_write);
}

int main(void)
{
 int c;   
 static struct termios oldt, newt;
 tcgetattr( STDIN_FILENO, &oldt);
 printf(".");
 newt = oldt;
 newt.c_lflag &= ~(ICANON | ECHO);
 tcsetattr( STDIN_FILENO, TCSANOW, &newt);
 char action;
 pid_t pid;
 signal(SIGUSR1,sig_read);
 signal(SIGUSR2,sig_write);
 pipe(fd);
 pid=fork();

if(pid==0)
{

 close(fd[1]);
 dup2(fd[0],0);  
 close(fd[0]);  
execl("draw.out","./draw.out",NULL);

}
else
{


 close(fd[0]);
 while((c=getchar())!='q')
 {
    printf(".");
    s1=(char)c;
    printf("%c\n",s1);
    write(fd[1],&c,1);
    
 }
}
 tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
 return 0;
}




