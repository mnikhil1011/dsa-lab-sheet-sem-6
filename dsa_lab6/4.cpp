#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],hash[n];
	
	int i=0;
	for(;i<n;i++)
	{
		scanf("%d",a+i);
		hash[i]=0;
	}
	int ptr1=0;	
	for(i=0;i<n;i++)
	{
		hash[a[i]]++;
		
		if(hash[a[ptr1]]==1)
			printf(" %d ",a[ptr1]);
		else
		{
			while(ptr1<=i)
			{
				ptr1++;
				if(hash[a[ptr1]]==1)
				{
					printf(" %d ",a[ptr1]);
					break;
				}
			}
			if(ptr1>i)
			{
				printf(" -1 ");
			}
					
		}		
	}	
	
}