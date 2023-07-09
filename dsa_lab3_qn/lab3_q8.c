#include<stdio.h>

int main()
{
	long n;
	scanf("%ld",&n);
	long l=0;
	long r=n;
	long ans;
	while(1)
	{
		long mid=(l+r)/2;
		if(mid*mid<=n && (mid+1)*(mid+1)>n)
		{
			ans= mid;
			break;	
		}
		else if((mid+1)*(mid+1)<n)
		{
			l=mid;
		}
		else 
		{
			r=mid;
		}
	}
	printf("%ld",ans);
}