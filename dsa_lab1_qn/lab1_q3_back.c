#include<stdio.h>

int back(int a[],int sum,int n,int *b)
{
	if(sum==0)
		return 1;
	else if(n==0)
		return 0;
	
	else if( back(a,sum,n-1,b) )
		return 1;
	else if(back(a,sum-a[n-1],n-1,b))
	{
	b[n]=1;
	return 1;
	}
	else{
		return 0;
	}		
	
}

int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	int a[n];
	for(;i<n;i++)
		scanf("%d",a+i);
	
	int sum;
	int b[n+1];
	scanf("%d", &sum);

	if(back(a,sum,n,b)==1)	
	{
	printf("yesssss");
	for(i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				printf("	%d",i-1);
			}
		}
	}
		
	else
		printf("no");	
	
}