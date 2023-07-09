#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	int i=0;
	for(;i<n;i++)
		scanf("%d",a+i);
	
	int hi=a[0],lo=0;
	i=0;
	for(;i<n;i++)
	{
		if(a[i]>hi)
			hi=a[i];	
	}
	int mid;
	while(1)
	{
		int count=0;

		mid=(hi+lo)/2;
				printf("%d	%d	%d	%d %d",mid,lo,hi,count);

		if(mid==0)
			break;
		i=0;
		for(;i<n;i++)
			count=count + a[i]/mid;
		if(count >k)
		{
			lo=mid;
		}
		else if( count < k)
		{
			hi= mid;
			continue;
		}
		int count2=0;
		i=0;
		for(;i<n;i++)
			count=count + a[i]/(mid+1);
		if(count2<k && count>k)
		{
			break;
		}	
		printf("%d	%d	%d	%d %d",mid,lo,hi,count2,count);
	}	
	
	printf("%d",mid);
	
}