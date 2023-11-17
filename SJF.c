#include<stdio.h>
#include<stdlib.h>
struct node{
 int pid,at,bt,ct,wt,tat,v;
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
  
  for(int i=0;i<n;i++)
  P[i].v=0;
  float awt=0,atat=0;
  for(int i=0;i<n;i++)
  {
    while(P[i].at>t)
     t++;
    int k=P[i].at;
    int min=9999;
    int x;
      for(int j=0;j<n;j++)
      {
        if( P[j].at<=t && min>P[j].bt && P[j].v!=1)
         {
       /*  if(min==P[j].bt)
         {
           if(P[j].at<P[x].at)
           {
              min=P[j].bt;
              x=j;
            }
         }
         else{
         */
         min=P[j].bt;
         x=j;
         //}
         }
       }
       P[x].ct=t+P[x].bt;
       printf("%d ",P[x].pid);
       t=P[x].ct;
       P[x].v=1;
       P[x].tat=P[x].ct-P[x].at;
       P[x].wt=P[x].tat-P[x].bt;
       awt=awt+P[x].wt;
       atat=atat+P[x].tat;
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
Enter number of Processor7
Enter Arrival Time and Brust time of each point
Processor 1:8 2

Processor 2:3 2

Processor 3:6 5

Processor 4:2 8

Processor 5:5 3

Processor 6:4 1

Processor 7:2 6
7 6 2 1 5 3 4 Processor id,Arrival Time,Brust Time,Completion Time,Waiting Time,Turn Around Time
4 2 8 29 19 27 
7 2 6 8 0 6 
2 3 2 11 6 8 
6 4 1 9 4 5 
5 5 3 16 8 11 
3 6 5 21 10 15 
1 8 2 13 3 5 
awt=7.14    Average tat=11.00
*/
