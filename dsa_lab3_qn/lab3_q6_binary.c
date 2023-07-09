#include<stdio.h>

int main()
{
   int n;
   scanf("%d",&n);
   int a[n];
   int i;
   for( i=0;i<n;i++)
       scanf("%d",&a[i]);

	int count=0;
	i =0;
	while(i <n)
	{
		int k=a[i];
		
		int l=i;int r=n;
		while(l<r)
		{
			int mid= (l+r)/2;
			if(a[mid]==k)
			{
				i=mid;
				l=i+1;
			}
			else 
			{
				r=mid-1;	
			}
		}
		i++;
		count++;
	}
	
	printf("%d",count);
   	
}