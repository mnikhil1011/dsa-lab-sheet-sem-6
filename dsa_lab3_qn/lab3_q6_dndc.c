#include<stdio.h>

void find(int a[],int* num,int lo, int hi,int b[])
{
	int mid=(lo+hi)/2;
	if(a[hi]==a[lo] )
	{
		int count =0;
		int i=0;
		while(b[i])
		{
			if (a[hi] == b[i])
			{
				count=1;
				break;
			}
			i++;
		}
		
		if(count ==0)
		{
			*num=*num+1 ;
			b[i]=a[lo];
		}
		return;
	}
	else
	{
		find(a,num,lo,mid,b);
		find(a,num,mid+1,hi,b);
	}	
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	int b[20]={};
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	
	//binary search;
	int num=0;
	find(a,&num,0,n-1,b);	
	printf("%d",num);
	
}