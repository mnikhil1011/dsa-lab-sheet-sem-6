#include<iostream>

using namespace std;

void swap(int *a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void heap(int*a,int i,int n)
{
	int l=2*i;
	int r=2*i+1;
	int larg=i;
	if(l<=n && a[l]>a[larg])
		larg=l;
	if(r<=n && a[r]>a[larg])
		larg=r;
		
	if(larg !=i)
	{
		swap(a,i,larg);
		heap(a,larg,n);	
	}		
		
}


void pop(int *a, int n)
{
	a[1]=a[n];
	heap(a,1,n-1);	
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

void build(int*a,int n,int k)
{
	for(int i=n/2;i>0;i--)
		heap(a,i,n);
	
	int ans=0;
	for(int i=0;i<k;i++)
	{
		int x=a[1];
		pop(a,n);
		push(a,n,x/2);
		ans+=x/2;
		if(x%2==1)
			ans++;
						
	}	
	
	cout<<endl<<ans<<endl;	
}





int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	build(a,n,k);
	
}