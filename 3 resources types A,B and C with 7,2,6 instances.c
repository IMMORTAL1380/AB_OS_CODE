#include<stdio.h>
 #include<stdlib.h>
  int n=5, m=3, i, j, l, k, a, b;
  

  int need[10][10],avail[10],total_resources[10];
  int total_resources[10]={7,2,6};
  int alloc[10][10]={   {0,1,0},
                        {2,0,0},
                        {3,0,2},
                        {2,1,1},
                        {0,0,2}
                    };
  int max[10][10]= {    {7,5,3},
                        {3,2,2},
                        {9,0,2},
                        {2,2,2},
                        {4,3,3}
                    };
  int choice;
  void display_alloc_need();
  void calculate_avail();
  void display_avail();
void main ()
{
        display_alloc_need();
        calculate_avail();
} 

void display_alloc_need()
{
printf ("Allocation\tMax\tNeed(Max-Allocation)");
printf ("\n");
for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
      printf ("%d ", alloc[i][j]);
    printf ("\t\t");
    for (j = 0; j < m; j++)
      printf ("%d ",max[i][j]);
    printf ("\t\t");
    for (j = 0; j < m; j++)
      {
	need[i][j] = max[i][j] - alloc[i][j];
	printf ("%d ", need[i][j]);
      }
    printf ("\n");
  }

}

void calculate_avail()
{
    int tot_alloc[10];
    for(i=0;i<10;i++)
        tot_alloc[i]=0;
        
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
       {
           tot_alloc[j]+=alloc[i][j];
       }
    for(i=0;i<m;i++)
        avail[i]=total_resources[i]-tot_alloc[i];
    printf("\nAVAIL\n");
    for(i=0;i<m;i++)
      printf("%d  ",avail[i]);
}
