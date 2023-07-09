#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=0;i<n;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			if(a[j]>0 &&a[j+1]<0)
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				break;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d	", a[i]);
	}
	
}