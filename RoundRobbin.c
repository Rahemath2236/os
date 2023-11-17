//Round Robin
#include<stdio.h>
#include<stdlib.h>
struct node{
 int at,bt,ct,wt,tat,tbt,v,pid,rat;
 };
 void sort(struct node P[],int n);
    void main()
 {
   int n,TQ;
   printf("Enter number of Processor and TQ"); 
   scanf("%d%d",&n,&TQ);
   struct node  P[n];
   int ct[n];
   printf("Enter Arrival Time and Brust time  of each processor");
   for(int i=0;i<n;i++)
   {
     // printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d",&P[i].at,&P[i].bt);
    }
    for(int i=0;i<n;i++)
   {
     P[i].v=0;
     P[i].tbt=0;
     P[i].rat=P[i].at;
    }
  sort(P,n);
  for(int i=0;i<n;i++)
   {
     P[i].v=0;
     P[i].tbt=0;
     P[i].rat=P[i].at;
    }
    int k=0,t=0;
    float awt=0,atat=0;
    while(P[0].at>t)
     t++;
   while(k!=n){
   int min=9999;
   int x; 
 
   for(int i=0;i<n;i++)
   {
      if(P[i].rat<=t && min>P[i].rat && P[i].v!=1)
       {
        min=P[i].rat;
        x=i;
       }
   }
   if(P[x].bt<TQ)
    {
     P[x].tbt=P[x].tbt+P[x].bt;
     P[x].ct=t+P[x].bt;
      t=t+P[x].bt;
     P[x].bt=0;
    P[x].tat=P[x].ct-P[x].at;
    P[x].wt=P[x].tat-P[x].tbt;
    P[x].v=1;
    k++;
    awt=awt+P[x].wt;
    atat=atat+P[x].tat;
    }
   else{
   P[x].bt=P[x].bt-TQ;
   P[x].tbt=P[x].tbt+TQ;
   P[x].rat=t+TQ+1;
   if(P[x].bt==0)
   {
      P[x].ct=t+TQ;
    P[x].tat=P[x].ct-P[x].at;
    P[x].wt=P[x].tat-P[x].tbt;
    P[x].v=1;
    k++;
    awt=awt+P[x].wt;
    atat=atat+P[x].tat;
   }
 }
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
   
     
     
   
        
       
    
    
    
    
