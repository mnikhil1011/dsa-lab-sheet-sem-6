#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int r= n;
	int l=0;
	int d= n*(n-1)/4;
	int mid;
	while(l<r)
	{
		mid=(l+r)/2;
		int midv= mid* (mid-1)/2;
		
		if(midv>d)
		{
			r=mid-1;
		}
		int midv1= midv+mid+1;
		if(midv<d)
		{
			l=mid+1;
		}
	}
	
	printf("\n%d",n-mid);
}