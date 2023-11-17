//Primtive Priority
#include<stdio.h>
#include<stdlib.h>


struct node{
 int pid,at,bt,ct,wt,tat,v,tbt,prio;
 };
 void sort(struct node P[],int n);
 void main()
 {
   int n;
   printf("Enter number of Processor");
   scanf("%d",&n);
   struct node  P[n];
   printf("Enter Arrival Time , Brust time and  priority of each point");
   for(int i=0;i<n;i++)
   {
      //printf("\nProcessor %d:",i+1);
      P[i].pid=i+1;
      scanf("%d%d%d",&P[i].at,&P[i].bt,&P[i].prio);
    }
  sort(P,n);
  
 for(int i=0;i<n;i++)
 {
   P[i].tbt=0;
   P[i].v=0;
  } 
  float awt=0,atat=0;
   int t=0,k=0;
  while(k!=n){ 
     int min=9999;
     int x;
        for(int i=0;i<n;i++)
           {
              if(P[i].at<=t && P[i].prio<min && P[i].v!=1)
                 {
                     min=P[i].prio;
                    x=i;
                  }
            }
  if(x>=0 && x<n){
       P[x].bt=P[x].bt-1;
       P[x].tbt=P[x].tbt+1;
       }
  if(P[x].bt==0)
     {
        P[x].ct=t+1;
        P[x].tat=P[x].ct-P[x].at;
        P[x].wt=P[x].tat-P[x].tbt;
        k++;
        P[x].v=1;
        awt=awt+P[x].wt;
        atat=atat+P[x].tat;
        printf("%d %d\n",P[x].pid,P[x].ct);
     }
  t=t+1;
  }
  printf("\nArrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor\n");
  for(int i=0;i<n;i++)
  {
     printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].tbt,P[i].prio,P[i].ct,P[i].tat,P[i].wt);
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
Enter number of Processor7
Enter Arrival Time , Brust time and  priority of each point
0 4 2
1 2 4
2 3 6
3 5 1
4 1 8
5 4 3
11 6 2
4 8
1 9
7 17
6 19
2 21
3 24
5 25

Arrival Time,Bruste Time,Priority ,Completion Time,Turn around Time ,Waiting Time of Each Processor
1	0	4	2	9	9	5
2	1	2	4	21	20	18
3	2	3	6	24	22	19
4	3	5	1	8	5	0
5	4	1	8	25	21	20
6	5	4	3	19	14	10
7	11	6	2	17	6	0
Average Wating time=10.29
 Average Turn Around Time= 13.86
 */  
  
