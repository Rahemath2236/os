#include <stdio.h>

void implimentWorstFit(int bs[], int b, int ps[], int p)
{
    int allocation[p];
    int occupied[b],i,j;
      for( i = 0; i < p; i++){
        allocation[i] = -1;
    }
    
    for(i = 0; i < b; i++){
        occupied[i] = 0;
    }
   for ( i=0; i < p; i++)
    {
	int indexPlaced = -1;
	for(j = 0; j < b; j++)
	{
	  if(bs[j] >= ps[i] && !occupied[j])
            {
                   if (indexPlaced == -1)
                    indexPlaced = j;
                else if (bs[indexPlaced] < bs[j])
                    indexPlaced = j;
            }
        }
   if (indexPlaced != -1)
        {
             allocation[i] = indexPlaced;
             occupied[indexPlaced] = 1;
            bs[indexPlaced] -= ps[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < p; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, ps[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 
int main()
{
    int p,b,ps[100],bs[100],i,j;
    printf("enter no.of process:");
    scanf("%d",&p);
    printf("enter no of blocks:");
    scanf("%d",&b);
    printf("enter processes size:");
    for(i=0;i<p;i++)
    {
    	scanf("%d",&ps[i]);
	}
	printf("enter block sizes:");
	for(i=0;i<b;i++)
	{
		scanf("%d",&bs[i]);
	}
    implimentWorstFit(bs,b,ps,p);
    return 0 ;
}
