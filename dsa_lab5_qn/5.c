#include<stdio.h>

int main()
{
	int k,n;
	scanf("%d%d", &n,&k);
	int a[n+1];
	int i=1;
	for(;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int ptr1=1,ptr2=2;
	int score=0;
	int amt=k;
	if(a[1]==0)
		amt--;

	while(ptr2<=n)
	{
		if(a[ptr2]==1)
		{
			ptr2++;
			
		}
		
		else if(amt>0)
		{
			amt--;
			ptr2++;
		}
		
		else
		{
			if(a[ptr1]==0)	
			{
				amt++;
			}
			ptr1++;
		}

		int temp= ptr2-ptr1;
		if(score<temp)
			score=temp;		
			
	}
	printf("\n%d",score);
}