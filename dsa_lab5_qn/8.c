#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	int i=0;
	for(;i<n;i++)
		scanf("%d",a+i);	
	int prefix[k];
	for(i=0;i<k;i++)
	{
		prefix[i]=0;
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		int temp=sum%k;
		prefix[temp]++;
		
	}
	int ans;
	ans+= prefix[0];
	
	for(i=0;i<k;i++)
	{
		if(prefix[i]>1)
			ans+= (prefix[i])*(prefix[i]-1)/2;
	}
	printf("%d",ans);
		
}