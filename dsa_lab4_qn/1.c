#include<stdio.h>

void merge(int a[][2],int l, int mid, int r)
{
		int p=mid-l+1;
		int q=r-(mid+1)+1;
		int i=0;
		int b[p][2],c[q][2];
		for(i=0;i<p;i++)
		{
			b[i][0]=a[l+i][0];
			b[i][1]=a[l+i][1];
		}
		for(i=0;i<q;i++)
		{
			c[i][0]=a[mid+1+i][0];
			c[i][1]=a[mid+1+i][1];

		}
		//now sorting using 2 pointers
		int x=0,y=0;
		i=l;
		while(x<p && y<q)
		{
			if(b[x][0]>c[y][0])
			{
				a[i][1]=c[y][1];
				a[i][0]=c[y][0];
				y++;
			}
			else
			{
				a[i][1]=b[x][1];
				a[i][0]=b[x][0];
				x++;
			}
			i++;
		}	
		while(x<p)
		{
			a[i][1]=b[x][1];
			a[i][0]=b[x][0];
			x++;
			i++;
		}	
		while(y<q)
		{
			a[i][1]=c[y][1];
			a[i][0]=c[y][0];
			y++;
			i++;
		}	
}

void mergesort(int a[][2],int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}

int overlap(int a[][2],int n)
{
	int index=0;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(a[index][1]>=a[i][0])
		{
			if(a[index][1]<a[i][1])
				a[index][1]=a[i][1];
			continue;	
		}
		index++;
		a[index][0]=a[i][0];
		a[index][1]=a[i][1];
	}
	
	return index+1;
}

int main ()
{
	int n,i;
	scanf("%d",&n);
	int a[n][2];
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	mergesort(a,0,n-1);
	int size=overlap(a,n);
	printf("\n%d \n",size);
	for(i=0;i<size;i++)
		printf("%d %d \n",a[i][0],a[i][1]);
	

	
}