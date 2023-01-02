#include<stdio.h>
int n=12,nf;
int in[20]={0,2,1,6,4,0,1,0,3,1,2,1};
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;

 void getdata()
 {
   printf("\nEnter no of frames:");
   scanf("%d",&nf);
 }
 
void initialize()
 {
  pgfaultcnt=0;
  for(i=0;i<nf;i++)
    p[i]=9999;
 }
 int isHit(int data)
 {
  hit=0;
      for(j=0;j<nf;j++)
       {
          if(p[j]==data)
            {
             hit=1;
              break;
               }
         }
      return hit;
 }
 
int getHitIndex(int data)
 {
  int hitind;
  for(k=0;k<nf;k++)
   {
         if(p[k]==data)
           {
             hitind=k;
              break;  
            }
   }
  return hitind;
 }

void disPages()
 {
    for (k=0;k<nf;k++)
    {
       if(p[k]!=9999)
               printf("%d",p[k]);
    }
 }
 
 void disPgFaultCnt()
 {
  printf("\nTotal no of page faults:%d",pgfaultcnt);
 }
 
 void fifo()
 {
   initialize();
   for(i=0;i<n;i++)
    {
         printf("\nFor %d:",in[i]);
  
         if(isHit(in[i])==0)
         {
           for(k=0;k<nf-1;k++)
           p[k]=p[k+1];
   
          p[k]=in[i];
          pgfaultcnt++;
          disPages();
    }
    else 
      printf("No page fault");
   }
   disPgFaultCnt();
}

 int main()
   {
      
      fifo();
   }
 
          

