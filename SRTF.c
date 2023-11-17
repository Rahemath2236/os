#include<stdio.h>
#include<stdlib.h>
struct node{
 int at,bt,ct,wt,tat,tbt,v,pid;
 };
 void sort(struct node P[],int n);
    void main()
 {
   int n;
   printf("Enter number of Processor"); 
   scanf("%d",&n);
   struct node  P[n];
   int ct[n];
   printf("Enter Arrival Time and Brust time  of each processor");
   for(int i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d",&P[i].at,&P[i].bt);
    }
  sort(P,n);
  for(int i=0;i<n;i++)
   {
     P[i].v=0;
     P[i].tbt=0;
    }
  int t=0,k=0;
  float awt=0,atat=0;
  while(k!=n){
  int min=9999;
  int x;
  while(P[0].at>t)
  t++;
  for(int i=0;i<n;i++)
  {
    if(P[i].at<=t && P[i].bt<min && P[i].v!=1)
    {
      min=P[i].bt;
      x=i;
     }
   }
  P[x].tbt=P[x].tbt+1;
  P[x].bt=P[x].bt-1;
  //printf("%d %d ",P[x].pid,P[x].bt);
  if(P[x].bt==0)
  {
    P[x].ct=t+1;
   // printf("%d ",t);
    P[x].tat=P[x].ct-P[x].at;
    P[x].wt=P[x].tat-P[x].tbt;
    P[x].v=1;
    k++;
    awt=awt+P[x].wt;
    atat=atat+P[x].tat;
   }
     t=t+1;
}
 printf("\nArrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor\n");
  for(int i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",P[i].pid,P[i].at,P[i].tbt,P[i].ct,P[i].tat,P[i].wt);
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
 Enter number of Processor6
Enter Arrival Time and Brust time  of each processor
Processor 1:0 8

Processor 2:1 6

Processor 3:2 5

Processor 4:3 2

Processor 5:4 4

Processor 6:5 1

Arrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor
1	0	8	26	26	18	
2	1	6	10	9	3	
3	2	5	19	17	12	
4	3	2	5	2	0	
5	4	4	14	10	6	
6	5	1	6	1	0	
Average Wating time=6.50
 Average Turn Around Time= 10.83
 *
 Arrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor
4	1	10	34	33	23	
6	1	8	24	23	15	
2	2	1	3	1	0	
7	2	6	17	15	9	
5	3	4	8	5	1	
3	4	3	11	7	4	
1	5	1	6	1	0	
Average Wating time=7.43
 Average Turn Around Time= 12.14/ 
  
  
  
  
