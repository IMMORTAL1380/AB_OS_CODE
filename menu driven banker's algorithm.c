#include<stdio.h>
#include<stdlib.h>
  int n,m,i,j,l,k,a,b;

  int need[10][10];
  int alloc[10][10];
  int max[10][10],avail[10];
  int choice;
    void get_data();
    void display_alloc_need();
    void display_avail();
   
int main()
 {
 while(1)
 {
  printf("\n**********MENU*************\n");
  printf("1.Accept ALLOCATION,MAX and AVAILABLE\n");
  printf("2.DisplayALLOCATION,MAX and NEED\n");
  printf("3.Display AVAILABLE\n");
  printf("4.EXIT\n");
  printf("Enter your choice....\n");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1:get_data();
        break;
   case 2:display_alloc_need();
        break;
   case 3:display_avail();
        break;
   case 4: exit(0);
 
}
}
}

void get_data()
{
  printf("Enter no of processe\n");
  scanf("%d",&n);

  printf("Entyer no of resources\n");
  scanf("%d",&m);

  printf("Enter ALLOCATION Matrix\n");
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
   scanf("%d",&alloc[i][j]);

printf("Enter AVAILABEL of size %d",m);
for(i=0;i<m;i++)
 scanf("%d",&avail[i]);
}
  
void display_alloc_need()
{
 
 printf("Allocation\t\t MAX\t\tNeed(MAX-Allocation)");
 printf("\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
         printf("%d",alloc[i][j]);
       printf("\t"); 
  for(j=0;j<m;j++)
   printf("%d",max[i][j]);
  printf("\t\t");
  
 for(j=0;j<m;j++)
 {
   need[i][j]=max[i][j]-alloc[i][j];
   printf("%d",need[i][j]);
  }
 printf("\n");
}

}

void display_avail()
{
int f[n],ans[n],ind=0;
for(k=0;k<n;k++)
 {
  f[k]=0;
}
printf("\nAvail matrix\n");
int y=0;
for(k=0;k<5;k++)
{
    for(i=0;i<n;i++)
      {
      if(f[i]==0)
       {
         int flag=0;
         for(j=0;j<m;j++)
          {
        if(need[i][j]>avail[j])
           {
             flag=1;
             break;
          }
          }
         if(flag==0)
             {
             ans[ind++]=i;
            for(y=0;y<m;y++)
             avail[y]+=alloc[i][j];
             f[i]=1;
            }
          }
            }
      }
for(i=0;i<m;i++)
 printf("%d",avail[i]);
printf("\n\nFollowing is the safe sequence\n");
for(i=0;i<n-1;i++)
 printf("p%d->",ans[i]);
printf("p%d",ans[n-1]);
}

