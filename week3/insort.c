#include<stdio.h>
void insertion_sort(int a[100],int n)
{
	int i,j,index;
	for( i=0; i < n; i++)
	{
		index = i;    
		j = 1;
		while((j>0) &&(a[j-1]> index)) 
		{
			a[j]=a[j-1];
			j= j-1;
		}
		a[j] = index;
	}					
}
int main()
{
	int a[100],i,n;
	printf("Enter size of the  array : ");
	scanf("%d", &n);
    	printf("Enter elements in array : ");
    	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n); 
	printf("\n  elements after sorting:\n ");
	for(i=0; i<n; i++)
    	{
       	printf("%d ",a[i]);
    	}
    
 }