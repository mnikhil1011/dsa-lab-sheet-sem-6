#include<stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char a[n];
	gets(a);
	gets(a);

	int ptr1=0,ptr2=0;
	int count=0;
	int ans=0;
	int i=0;
	int b[k];
	for(;i<k;i++)
	{
		b[i]=0;
	}
	while(ptr2<n)
	{
		if(b[a[ptr2]-'a']==0)
		{
			count++;
		}
		b[a[ptr2]-'a']++;
		
	
		while(count==k)
		{
			b[a[ptr1]-'a']--;
			if(b[a[ptr1]-'a']==0)
				count--;
			ptr1++;
		
			ans += n- ptr2;	
		}
		
		ptr2++;
		
		printf("\n %d %d %d %d",ptr1,ptr2, count , ans);
		
		
	}
	
	printf("\n%d", ans);
	
	
}