#include<iostream>

using namespace std;

void swap(int*a,int l,int r)
{
	int temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}

void heap(int*a,int n,int i)
{
	int l=2*i;
	int r=2*i+1;
	int temp=i;
	if(l<=n && a[l]>a[temp])
		temp=l;
	if(r<=n && a[r]>a[temp])
		temp=r;	
	
	if(temp !=i)
	{
		swap(a,i,temp);
		heap(a,n,temp);
	}	
		
}

void pop(int *a, int n)
{
	a[1]=a[n];
	heap(a,n-1,1);	
}

void heapify(int *a,int x)
{
	int parent=x/2;
	if(parent>0)
	{
		if(a[parent]<a[x])
		{
			swap(a,x,parent);
			heapify(a,parent);
		}
	}
}

void push(int *a, int n,int x)
{
	a[n]=x;
	heapify(a,n);
}
void makeheap(int*a, int n,int k)
{
	for(int i=n/2 ;i>0;i--)
		heap(a,n,i);
		
	for(int i=0;i<k;i++)
	{
		int x=a[1];
		pop(a,n);
		push(a,n,x/2);
	}	
}

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	makeheap(a,n,k);	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans +=a[i];
	}
	
	cout<<ans;	
		
}