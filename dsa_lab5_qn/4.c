#include<Stdio.h>

int main()
{
	int n,k,t,i;
	scanf("%d%d%d",&n,&k,&t);
	int ptr1=1;
	int ptr2=1;
	int a[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	int score=0;
	int count=0;
	while(ptr2<=n)
	{
		if(ptr2<k)
		{
			score+= a[ptr2];
			ptr2++;
			continue;
		}
		else if(ptr2 == k)
		{
			score+= a[ptr2];
			ptr2++;
			int av=score/k;
			if(av>=t)
			{
				count++;
			}
			continue;
			
		}
		score-= a[ptr1];
		ptr1++;
		score+= a[ptr2];
		ptr2++;
		int av=score/k;
		if(av>=t)
		count++;
	}
	
	printf("%d",count);
}