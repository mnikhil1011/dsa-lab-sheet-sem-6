#include<stdio.h>


void merge(int * a , int l, int mid, int r)
{
	int p=mid-l+1,q=r-mid;
	int i;
	int b[p],c[q];
	for(i=0;i<p;i++)
	{
		b[i]=a[i+l];
	}
	for(i=0;i<q;i++)
	{
		c[i]=a[i+mid+1];
	}
	i=l;
	int j=0,k=0;
	while(j<p && k<q)
	{
		if(b[j]<c[k])
		{
			a[i]=c[k];
			k++;
		}
		else
		{
			a[i]=b[j];
			j++;
		}
		i++;
	}
	while(j<p)
	{
		a[i]=b[j];
		j++;
		i++;
	}
	while(k<q)
	{
		a[i]=c[k];
		k++;
		i++;
	}
}

void mergesort(int *a,int l,int r)
{
	if(l<r)
	{
		int mid= (l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",a+i);
		
	mergesort(a,0,n-1);	
	
	for(i=1;i<=n;i++)
	{
		printf("%d ",i);
		if(a[i-1]<i)
			break;
	}
	printf("\n%d\n",i-1);

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}