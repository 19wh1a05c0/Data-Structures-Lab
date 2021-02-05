#include<stdio.h>
void sin_sort(int a[100],int n)
{
	int i,j,min,t;
	for( i=0; i < n-1; i++)
	{
		min = i;      
		for(j=i+1; j<n; j++)
		{
			if(a[j]<a[min])
			min = j;
		}
           		t = a[i];
           		a[i]=a[min];
           		a[min]=t;
		
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
	sin_sort(a,n); 
	printf("\n  elements after sorting:\n ");
	for(i=0; i<n; i++)
    	{
       	printf("%d ",a[i]);
    	}
    
 }