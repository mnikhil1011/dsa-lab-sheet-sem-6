#include<stdio.h>

void backtrack(int *a, int n, int * b, int k,int layer,int * min,int max)
{
	if (layer== n)
	{		
		if(*min>max)
			*min=max;
		return;
	}
	int i=0;
	for(;i<k;i++)
	{
		b[i]+= a[layer];
		int temp=max;
		if(b[i]>max)
			max=b[i];
		backtrack(a,n,b,k,layer+1,min,max);	
		max=temp;
		b[i]-=a[layer];
	}
	
}

int main()
{
	int k,n;
	scanf("%d%d",&n,&k);
	int i=0,a[n];
	for(;i<n;i++)
		scanf("%d",a+i);
	
	int b[k];
	for(i=0;i<k;i++)
		b[i]=0;
	int min=100000;
	backtrack(a,n,b,k,0,&min,-1);
	
	printf("\n%d",min);
}