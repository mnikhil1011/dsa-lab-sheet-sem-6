#include<stdio.h>

int main()
{
	int n,i=0;
	scanf("%d",&n);
	int a[n];
	for(;i<n;i++)
		scanf("%d",&a[i]);
	int zeros[n];
	for(i=0;i<n;i++)
	{
		int t=a[i],z=0;
		while(t>0)
		{
			t=t/5;
			z=z+t;
		}
		zeros[i]=z;
	}

	int max=zeros[0];
	for(i=0;i<n;i++)
		if(zeros[i]>max)
			max=zeros[i];
	int count[max+1];
	for(i=0;i<=max;i++)
		count[i]=0;

	for(i=0;i<n;i++)
		count[zeros[i]]++;
	int ans=0;
	
	for(i=0;i<=max;i++)
	{
		if(count[i]==1 || count[i]==0)
			continue;
			
		int f=count[i];
		ans += f*(f-1)/2;		
	}	
	printf("%d",ans);	
	

	
	
		
}