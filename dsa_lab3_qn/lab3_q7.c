#include<Stdio.h>

int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	int i=0,a[n];
	int mid;
	for(;i<n;i++)
		scanf("%d",a+i);
	int l=0,r=n;
	int j=10;
	while(j--)
	{
		mid=(l+r)/2;
		if(d==a[mid])
			break;
		if(d<a[mid])
		{
			r=mid;
		}
		if(d>a[mid])
		{
			l=mid;	
		}	
		if(d>a[mid] && d<a[mid+1])
			break;
	}
	
	printf("\n%d ",a[mid]);
}