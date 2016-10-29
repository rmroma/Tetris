#include <stdio.h>
#include <termios.h>            //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>
#include <sys/fcntl.h>
#include <signal.h>
#include <stdlib.h>

char board[20][20];
void createBoard(char board[20][20])
{
 int i,j;
 for(i=0;i<20;i++)
 
 {
   for(j=0;j<20;j++)
     {
       board[i][j]='*';
     }
 }
 board[0][8]='-';
 board[0][9]='-';
 board[0][10]='-';
}

void addNew(char board[20][20])
{
if(board[0][8]=='*' && board[0][9]=='*' && board[0][10]=='*')
{
 board[0][8]='-';
 board[0][9]='-';
 board[0][10]='-';
}
else
	exit(1);
}
void printBoard(char board[20][20])
{
 int i,j;
 for(i=0;i<20;i++)
 {
   for(j=0;j<20;j++)
     {
       if(i==19)
          printf("%c",board[i][j]);
       else
       if(j==0 ||j==19)            
          printf("%c",board[i][j]);
       else
         if(board[i][j]=='-')
           printf("%c",board[i][j]);
          else
          if(board[i][j]=='$')
             printf("-");
       else
          if(board[i][j]=='a')
            printf("a");
        else
       printf(" ");

     }
      printf("\n");
 }

}

void actionRight(char board[20][20])
{
 int i,j;
 int mone=0;
 int k=0,t=0;
 int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
 int count=1;
 system("clear");
 for(i=0;i<20;i++)
  {
   for(j=0;j<20;j++)
   {
    if(board[i][j]=='-')
       {
         if(count==1)
         {
          count=2;
          b1=i;
          a1=j;
         }
         else
         if(count==2)
         {
          b2=i;
          count=3;
          a2=j;
         }
         else
         if(count==3)
         {
          count=4;
          b3=i;
          a3=j;
         }
       }
   }
   }

if(b3==18)
{
  board[b1][a1]='$';
  board[b2][a2]='$';
  board[b3][a3]='$';

 addNew(board);
}
else
if(a3!=18)
{
if((a1+1==a2)&&(a2+1==a3))
 {
  if(board[b3][a3+1]=='$')
   {
     
   }
   else
   {
   board[b3][a3+1]='-';
   board[b1][a1]='*';
   }
}
else
{
 if(board[b3][a3+1]=='$' || board[b2][a2+1]=='$' || board[b1][a1+1]=='$')
 {

 }
 else{
 board[b1][a1]='*';
 board[b2][a2]='*';
 board[b3][a3]='*';
 board[b1][a1+1]='-';
 board[b2][a2+1]='-';
 board[b3][a3+1]='-';
 }
}
}

  
   printBoard(board);
}

void actionUp(char board[20][20])
{

 int i,j;
 int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
 int count=1;
 system("clear");
 for(i=0;i<20;i++)
  {
   for(j=0;j<20;j++)
   {
    if(board[i][j]=='-')
       {
         if(count==1)
         {
          count=2;
          b1=i;
          a1=j;
         }
         else
         if(count==2)
         {
          b2=i;
          count=3;
          a2=j;
         }
         else
         if(count==3)
         {
          count=4;
          b3=i;
          a3=j;
         }
       }
   }
   }

if(b3==18)
{
  board[b1][a1]='$';
  board[b2][a2]='$';
  board[b3][a3]='$';
 addNew(board);
}
else
{
 if(b2!=0 && b2!=18)
 if((a1+1)==a2&& (a2+1)==a3)
  {
    if(board[b2+1][a2]=='$')
     {
     }  
    else
    {
    board[b2+1][a2]='-';
    board[b2-1][a2]='-';
    board[b1][a1]='*';
    board[b3][a3]='*';
  }}
  if(a1!=1 && a1!=18)
  if(b1+1==b2 && b2+1==b3)
    {
     if(board[b2][a1+1]=='$' || board[b2][a1-1]=='$')
      {
      }
      else
      {
     board[b2][a2+1]='-';
     board[b2][a2-1]='-';
     board[b1][a1]='*';
     board[b3][a3]='*';

    }
}
 }  
 printBoard(board);


               
} 

void actionLeft(char board[20][20])
{
  int i,j;
 int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
 int count=1;
 system("clear");
 for(i=0;i<20;i++)
  {
   for(j=0;j<20;j++)
   {
    if(board[i][j]=='-')
       {
         if(count==1)
         {
          count=2;
          b1=i;
          a1=j;
         }
         else
         if(count==2)
         {
          b2=i;
          count=3;
          a2=j;
         }
         else
         if(count==3)
         {
          count=4;
          b3=i;
          a3=j;
         }
       }
   }
  }
if(b3==18)
{
  board[b1][a1]='$';
  board[b2][a2]='$';
  board[b3][a3]='$';
 addNew(board);
}
else
{
if(a1!=1)
if((a1+1==a2)&&(a2+1==a3))
 {
  if(board[b1][a1-1]=='$')
     {
      
     }
   else 
   {
   board[b1][a1-1]='-';
   board[b3][a3]='*';
}}
else
{
 if(board[b1][a1-1]=='$' || board[b2][a2-1]=='$' || board[b3][a3-1]=='$')
{
  
}
 else
 {
 board[b1][a1]='*';
 board[b2][a2]='*';
 board[b3][a3]='*';
 board[b1][a1-1]='-';
 board[b2][a2-1]='-';
 board[b3][a3-1]='-';
}
}
}
   printBoard(board);


}


void actionDown(char board[20][20])
{
int i,j;
 int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
 int mone=0;
 int k=0,t=0;
 int count=1;
 int temp=0;
 int flag=1;
 system("clear");
 for(i=0;i<20;i++)
  {
   for(j=0;j<20;j++)
   {
    if(board[i][j]=='-')
       {
         if(count==1)
         {
          count=2;
          b1=i;
          a1=j;
         }
         else
         if(count==2)
         {
          b2=i;
          count=3;
          a2=j;
         }
         else
         if(count==3)
         {
          count=4;
          b3=i;
          a3=j;
         }
       }
  
} }
  
if(b3==18)
{
 board[b1][a1]='$';
 board[b2][a2]='$';
 board[b3][a3]='$';

 addNew(board);
 }
else
{
if(b3!=18)
{
if((a1+1==a2)&&(a2+1==a3))
 {
  if(board[b1+1][a1]=='$' || board[b2+1][a2]=='$' || board[b3+1][a3]=='$')
    { 
  board[b1][a1]='$';
  board[b2][a2]='$';
  board[b3][a3]='$';
  addNew(board);
     }
   else
   {
 board[b1][a1]='*';
 board[b2][a2]='*';
 board[b3][a3]='*';
 board[b1+1][a1]='-';
 board[b2+1][a2]='-';
 board[b3+1][a3]='-';
}
}
else
{ 
 if(board[b3+1][a3]=='$')
 {
  board[b1][a1]='$';
  board[b2][a2]='$';
  board[b3][a3]='$';
  addNew(board);
   }
  else
{
 board[b1][a1]='*';
 board[b3+1][a3]='-';
}
}}}

for(i=0;i<19;i++)
   {
   for(j=1;j<19;j++)
    {
      if(board[i][j]=='$')
        mone++;
    } 
     if(mone==18)
       {
         for(t=1;t<19;t++)
            board[i][t]='*';
            flag=0;
       }
       

     mone=0;
   } 

            if(flag==0)
{
           for(i=0;i<18;i++)
              {
                 for(j=1;j<19;j++)
                  {
           
                        if(board[i][j]=='$'&&(board[i-1][j]=='$' || board[i-1][j]=='a') && board[i+1][j]=='*')
                              {
                               board[i+1][j]='$';
                               board[i][j]='$';
                               
                                  
                              }
                          if(board[i][j]=='$'&&(board[i-1][j]=='$' || board[i-1][j]=='a') && board[i+1][j]=='$')
                              {
                               
                              
                               board[i][j]='$';
                               board[i+1][j]='$';                                 
               
                              }


                     if(board[i][j]=='$'&& board[i+1][j]=='$' && board[i-1][j]=='*' && board[i-1][j]!='a' )
{
                        board[i][j]='a';
                               
                               board[i+1][j]='$';                        

                      
}

{
                   
                      if(board[i][j]=='$' && board[i+1][j]=='*' && board[i-1][j]=='*')
                        {
                           board[i+1][j]='$';
                           board[i][j]='*';
                           printf("4\n");
                        }

                    }    


                  













              }
   


}



             }
           for(i=0;i<19;i++)
              for(j=1;j<19;j++)
                 if(board[i][j]=='a')
                     board[i][j]='*';

  printBoard(board);


}

void sig(int x)
{ 
 actionDown(board);
  alarm(1);
}
int main(void)
{
 int file;
 int readAction;
 int writeAction;
 char c;   
 static struct termios oldt, newt;
 tcgetattr( STDIN_FILENO, &oldt);
    
 newt = oldt;
 newt.c_lflag &= ~(ICANON | ECHO);
 tcsetattr( STDIN_FILENO, TCSANOW, &newt);
 char action;
 pid_t pid;
 createBoard(board);
 printBoard(board);

 signal(SIGALRM,sig);
 alarm(1);
 scanf("%c",&c);
 while(c!='q')
 {
  if(c=='a')
   {
   actionLeft(board);
   }
  if(c=='d')
    actionRight(board);
  if(c=='s')
    actionDown(board);
  if(c=='w')
    actionUp(board);
    scanf("%c",&c);

 }

 tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
 return 0;
}


