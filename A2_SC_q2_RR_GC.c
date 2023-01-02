#include<stdio.h>
 
 void main()
 {
  int i,k,NOP=6, sum=0,count=0,y,quant=4,tat=0,at[6]={0,1,2,3,4,6};
  int org_bt[6], bt[6]={5,6,3,1,5,4},gantt_CT[20],temp[10],cmp_T=0;
  float avg_wt=0.0,avg_tat=0.0;
 int Total_wt=0,Total_TT,pos=0,turn=0;
 char process_completed='N';
  int wt[20],CT[20],TT[20],RT[20],j,n;
  int p[20];
 y=NOP;
 
 printf("\n=======Round Robin===========\n");
 printf("\n Gantt Chart  \n");
  printf("");
   for(i=0;i<=(NOP+3)*8;i++)
  printf("-");
 
 printf("\n");
 printf("|");
   for(i=0;i<NOP;i++)
    {
 
     CT[i]=0;
     gantt_CT[i]=0;
     org_bt[i]=bt[i];
    }
  XYZ:
 for(i=0;i<NOP;i++)
  {
 if(bt[i]>0)
 {
  if(quant>bt[i])
  {
   cmpl_T+=bt[i];
   bt[i]=0;
  }
 else
 {
 cmpl_T+=quant;
 bt[i]=bt[i]-quant;
 }
 if(turn==0)
  gantt_CT[i]=cmp_T;
 else
 gantt_CT[k++]=cmpl_T;
 
 printf(" p%d |",i+1);
 if(bt[i]==0)
 {
 CT[i]=cmpl_T;
 TT[i]=CT[i]-at[i];
 wt[i]=TT[i]-bt[i];
 RT[i]=wt+=wt[i];
 Total_wt+=wt[i];
 Total_TT+=TT[i];
 }
}
    }
   if(turn==0)
   k=1;
   for(i=0;i<NOP;i++)
   {
 if(bt[i]==0)
  process_completed='Y';
 else
  {
  process_completed='N';
  break;
   }
}
 if(process_completed=='N')
 {
 turn++;
 goto XYZ;
 }
printf(" ");
 printf("\n");
 for(i=0;i<k*8;i++)
  {
   printf("-");
  }
 printf("\n0");
 for(i=0;i<k;i++)
   printf("%8d",gantt_CT[i]);
 
 printf("\n\nPID\t AT \tBT \tCT\tTT\tWT\tRT \n");
 printf("---------------------------------------");
 for(i=0;i<NOP;i++)
 printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],org_bt[i],CT[i],TT[i],wt[i],RT[i]);
 printf("\n\n Average Waiting Time:\t%.2f",(float)Total_wt/NOP);
 printf("\n\n Average Turn Around Time:\t%.2f",(float)Total_TT/NOP);
  }


 
