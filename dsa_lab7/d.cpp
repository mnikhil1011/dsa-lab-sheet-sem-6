#include<iostream>

using namespace std;

void change(int *a,int n,int * sum,int locn)
{
	if(locn>n||a[locn]==-1)
		return;
	change(a,n,sum,2*locn+1);
	
	*sum=*sum+a[locn];
	a[locn]=*sum;
	change(a,n,sum,2*locn);
	
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	change(a,n,&sum,1);
	
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}

	
}