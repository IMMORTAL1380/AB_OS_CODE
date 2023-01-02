#include<stdio.h>
int Resources(int p,int n)
{
int r =0;
 r=p*(n-1)+1;

return r;
}
int main()
{
int process,need;
printf("enter the no of process and max need of every process:\t");
scanf("%d%d",&process,&need);

printf("R>=%d",Resources(process, need));

return 0;



}
