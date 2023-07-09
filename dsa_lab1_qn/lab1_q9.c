#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&k,&n);
	int mid=(k+1)/2;
	int a[n+1];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>=mid && a[j+1]<=mid)
			{
				int temp= a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
    
}