#include <stdio.h>
  
int main() 
{
      int AT[10], BT[10], temp[10];
      int i, smallest, count = 0, time, n;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      printf("\nEnter Details of %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &AT[i]);
            printf("\nEnter Burst Time:\t");
            scanf("%d",&BT[i]); 
            temp[i] = BT[i];
      }
      BT[9] = 9999;  
      for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(AT[i] <= time && BT[i] < BT[smallest] && BT[i] > 0)
                  {
                        smallest = i;
                  }
            }
            BT[smallest]--;
            if(BT[smallest] == 0)
            {
               count++;
               end = time + 1;
               wait_time = wait_time + end - AT[smallest] - temp[smallest];
               turnaround_time = turnaround_time + end - AT[smallest];
            }
      }
      average_waiting_time = wait_time / n; 
      average_turnaround_time = turnaround_time / n;
      printf("\n\nAverage Waiting Time:t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:t%lf\n", average_turnaround_time);



      return 0;

}


