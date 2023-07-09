#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i=-1;
	int a[n];
	while(++i<n)
		scanf("%d",a+i);
	
	int odd=0,ans=0;
	int prefix[n];
	for(i=0;i<n;i++)
	{
		prefix[i]=0;
		prefix[odd]++;
		if(a[i]%2==1)
			odd++;
		if(odd>=k)
		{
			ans+=prefix[odd-k];
		}	
	}
	
	printf("\n%d\n",ans);
	for(i=0;i<n;i++)
	{
		printf("%d ",prefix[i]);
	}
	
	
}