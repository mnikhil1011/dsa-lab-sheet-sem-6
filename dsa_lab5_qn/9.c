#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n];
	int i=0;
	for(;i<n;i++)
	{
		scanf("%d",a+i);
	}
	
	int ptr1=0,ptr2=0,temp=0;
	int ans=0,count=0;
	while(ptr2<n)
	{
		if(a[ptr2]%2==1)
		{
			count++;
		}
		
		if(count==k)
		{
			temp=ptr2;
			ptr2++;
			while(a[ptr2]%2==0 && ptr2<n)
				ptr2++;
				
			while(count==k)
			{
				if(a[ptr1]%2==1)
				{
					count--;
				}
				ans+= ptr2-temp;
				ptr1++;	
			}	
		}
		else
		{
			ptr2++;
		}
	}
	
	printf("\n%d",ans);
}