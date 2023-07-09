#include<stdio.h>
#include<stdlib.h>

void fq(int*a,int*f,int*b,int n,int x)
{
	if(*f==-1)
	{
		*f=0;
		*b=0;
		a[*f]=x;
		return;
	}
	*f=*f-1;
	if(*f==-1)
		*f=n-1;
	a[*f]=x;
	return;	
}

void bq(int*a,int*f,int*b,int n,int x)
{
	
	*b=*b+1;
	if(*b==n)
		*b=0;
	a[*b]=x;
	return;	
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	int deq[n];
	int f=-1,b=-1;
	
	for(i=0;i<n;i++)
	{
		if(f==-1 || a[i]<deq[f])
			fq(deq,&f,&b,n,a[i]);
		else
			bq(deq,&f,&b,n,a[i]);	
	}
	
	
	for(i=0;i<n;i++)
		printf("%d ",deq[(f+i)%n]);
	
	
}