#include<stdio.h>
int main()
{
  
int n,m,i,j,l,k,a,b;
n=5;
m=3;
int need[n][m];

int alloc[5][3]={{0,1,0},
   {2,0,0},
   {3,0,2},
   {2,1,1},
   {0,0,2}};


int max[5][3] = {{7,5,3},
  
   {3,2,2},
   {9,0,2},
   {2,2,2},
   {4,3,3}};
printf("Allocation\t   Max\t\tNeed(Max-Allocation)");
printf("\n");
 for(a=0;a<n;a++)
{
   for(b=0;b<m;b++)
      printf("%d ",alloc[a][b]);
    printf("\t\t");
   for(b=0;b<m;b++)
      printf("%d ",max[a][b]);
    printf("\t\t");
   for(b=0;b<m;b++)
    {
      need[a][b] = max [a][b]-alloc[a][b];
      printf("%d ",need[a][b]);
    }
  printf("\n");
}  
   

int avail[3]=  {3,3,2};
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
  if (need[i][j]>avail[j])
{
    flag=1;
    break;
}
}
if(flag==0)
{
  ans[ind++]=i;
  for(y=0;y<m;y++)
  avail[y]+=alloc[i][y];
  f[i]=1;
}
}
}
}
for(i=0;i<m;i++)
  printf("%d  ",avail[i]);
printf("\n\nFollowing is the safe sequence\n");
for(i=0;i<n-1;i++)
  printf("p%d->",ans[i]);
printf("p%d",ans[n-1]);
return (0);
}
 

