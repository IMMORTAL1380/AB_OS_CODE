#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   int pid=fork();
   if(pid>0)
 {
     printf("in parent process\n");
     printf("PID: %d\n",getpid());
  }
   else if(pid==0)
  {
    sleep(10);
    printf("\nin child process");
    printf("\nPID: %d",getppid());
    printf("\nChild PID:%d",getpid());
  }
    return 0;
 }
