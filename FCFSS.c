//FCFS Algorithm
#include<stdio.h>
#include<stdlib.h>
struct node{
 int pid,at,bt,ct,wt,tat;
 };
 void sort(struct node P[],int n);
 void main()
 {
   int n;
   printf("Enter number of Processor");
   scanf("%d",&n);
   struct node  P[n];
   int ct[n];
   printf("Enter Arrival Time and Brust time of each point");
   for(int i=0;i<n;i++)
   {
      printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d",&P[i].at,&P[i].bt);
    }
  sort(P,n);
 int t=0;
 int min=9999;
 float awt=0,atat=0;
 for(int i=0;i<n;i++)
 {
    
    while(P[i].at>t)
     t++;
    P[i].ct=t+P[i].bt;
     t=t+P[i].bt;
    P[i].tat=P[i].ct-P[i].at;
    P[i].wt=P[i].tat-P[i].bt;
    awt=awt+P[i].wt;
    atat=atat+P[i].tat;
    
  }
      
      
  printf("Processor id,Arrival Time,Brust Time,Completion Time,Waiting Time,Turn Around Time\n");
   for(int i=0;i<n;i++)
  printf("%d %d %d %d %d %d \n",P[i].pid,P[i].at,P[i].bt,P[i].ct,P[i].wt,P[i].tat);
 printf("awt=%.2f    Average tat=%.2f",awt/n,atat/n); 
  
 } 
void sort(struct node P[],int n)
{
   for(int i=0;i<n-1;i++)
   {
     for(int j=0;j<n-i-1;j++)
     {
       if(P[j+1].at<P[j].at)
       {
         struct node t=P[j];
         P[j]=P[j+1];
         P[j+1]=t;
        }
      }
    }
}

/*
Enter number of Processor4
Enter Arrival Time and Brust time of each point
Processor 1:2 3

Processor 2:1 6

Processor 3:2 9

Processor 4:4 2
Processor id,Arrival Time,Brust Time,Completion Time,Waiting Time,Turn Around Time
2 1 6 7 0 6 
1 2 3 10 5 8 
3 2 9 19 8 17 
4 4 2 21 15 17 
awt=7.00    Average tat=12.00
*/
