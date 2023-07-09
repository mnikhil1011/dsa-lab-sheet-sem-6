#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int long long int


int recursion(int l, int r , int n, int layer)
{
	if(l + pow(2,layer)>r)
	{
		//printf("%d", n);
		return l;
	}
	
	if(layer %2== 0)
	{
		l=l+pow(2,layer);
		if(n%2==1)
		{
			r=r-pow(2,layer);
		}
	}
	else
	{
		r=r-pow(2,layer);
		if(n%2==1)
		{
			l=l+pow(2,layer);
		}
	}
	recursion(l,r,n/2,layer+1);
}


int main()
{
	int n;
	scanf("%lld",&n);
	printf("\n\n%d",recursion(1,n,n,0));	
}