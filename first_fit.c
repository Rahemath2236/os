// use structure for memory blocks 
#include<stdio.h>
int main()
{
  int n;
  printf("enter no.of process:");
  scanf("%d",&n);
  int p[n],m[n],fill[n];
  printf("enter process memory");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("enter memory blocks:");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&m[i]);
  }
  printf("kkkkk");
  for(int i=0;i<n;i++)
  {
    fill[i]=0;
    }
    int i=0,s=0;
    int e=0;
  while(s!=4)
  {
    
    if(m[e]>=p[i] && fill[e]==0) {
    fill[e]=i+1;
    i++;
    //e++;
    s++;
    e=0;}
    else{
      e++;}
  }
  for(int i=0;i<n;i++)
  {
    printf("%d\n",fill[i]);
    } 
  return 0;
}
