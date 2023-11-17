//Non Primtive Priority Schelduling
#include<stdio.h>
#include<stdlib.h> 
struct node{
int pid,at,bt,ct,wt,tat,prio,v;
 };
 void sort(struct node P[],int n);
 void main()
 {
   int n;
   printf("Enter number of Processor");
   scanf("%d",&n);
   struct node  P[n];
   int ct[n];
   printf("Enter Arrival Time and Brust time and Priority of each point");
   for(int i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d%d",&P[i].at,&P[i].bt,&P[i].prio);
    }
  sort(P,n);
  int t=0;
  for(int i=0;i<n;i++)
  P[i].v=0;
  
  float atat=0,awt=0;
  printf("Gantt Chart\n");
  for(int i=0;i<n;i++)
  {
     if(t<P[i].at)
       printf("Idle ");
     while(t<P[i].at)
       t++;
     int min=9999;
     int x;
     for(int j=0;j<n;j++)
     {
         if(P[j].at<=t && P[j].prio<min && P[j].v!=1)
         {
             min=P[j].prio;
             x=j;
          }
      }
     P[x].ct=t+P[x].bt;
     
     //printf("%d - %d ",x,P[x].ct);
     P[x].tat=P[x].ct-P[x].at;
     P[x].wt=P[x].tat-P[x].bt;
     t=P[x].ct;
     P[x].v=1;
     awt=awt+P[x].wt;
     atat=atat+P[x].tat;
     printf("%d ",P[x].pid);
    }
  printf("\nArrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor\n");
  for(int i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].bt,P[i].prio,P[i].ct,P[i].tat,P[i].wt);
  }
  printf("Average Wating time=%.2f\n Average Turn Around Time= %.2f",awt/n,atat/n);
}
void sort(struct node P[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(P[j].at>P[j+1].at)
      {
       struct node t=P[j];
       P[j]=P[j+1];
       P[j+1]=t;
      }
    }
  }
}

 /*
 Enter number of Processor5
Enter Arrival Time and Brust time and Priority of each point
Processor 1:0 1 2

Processor 2:2 7 1

Processor 3:2 4 3

Processor 4:7 9 4

Processor 5:6 2 3
Gantt Chart
1 Idle 2 3 5 4 
Arrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor
1	0	1	2	1	1	0
2	2	7	1	9	7	0
3	2	4	3	13	11	7
5	6	2	3	15	9	7
4	7	9	4	24	17	8
Average Wating time=4.40
 Average Turn Around Time= 9.00
 */   
          
    
       
     
