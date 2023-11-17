#include<stdio.h>
int main()
{
 int n;
  printf("enter no.of process:");
 scanf("%d",&n);
  int p[n],m[n],fill[n],index[n];
  printf("enter process memory:");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("enter memory blocks:");
  for(int i=0;i<n;i++)
  { index[i]=i;
    scanf("%d",&m[i]);
  }
  for(int i=0;i<n;i++)
  {
    fill[i]=-1;
    }
    
  for(int i=n-1;i>0;i--)
  {
   for( int j=0;j<=i-1;j++)
   {
     if(m[j]>m[j+1]){
      int temp=m[j];
      m[j]=m[j+1];
      m[j+1]=temp;
      
      temp=index[j];
      index[j]=index[j+1];
      index[j+1]=temp;}
     }
   }
   printf("aftre sort");
   for(int i=0;i<n;i++)
   {
    printf("%d %d \n",m[i],index[i]);
    }
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<n;j++)
   {
     if(m[j]>=p[i] && fill[index[j]]==-1)
     {
       fill[index[j]]=i+1;
       break;
       }
    }
  }
  printf("the process:\n");
  for(int i=0;i<n;i++)
  {
    printf("%d\n",fill[i]);
   }
   return 0;
 }  
