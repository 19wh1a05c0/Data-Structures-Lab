#include <stdio.h>
void bub_sort( int a[50],int n)
{
	int i ,j,t;
	 for (i = 0; i < n-1; i++)
	{
	 	for (j = 0; j < n-i-1 ; j++)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
int main()
{
	int a[50], n, i;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	printf("Enter %d integers\n", n);
	for(i = 0;i <n; i++)
	{
	scanf("%d\n", &a[i]);
	}
	bub_sort(a,n);
	printf(" elements after sorting \n");
	for(i = 0; i < n; i++)
	{
		printf("%d\n",a[i]);
	}
}