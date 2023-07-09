#include<iostream>
#include<queue>
using namespace std;

void find(int*a,int*k,int n,int locn)
{
	if(locn>n||a[locn]==-1)
	{
		return;
	}
	
	find(a,k,n,locn*2+1);
	
	*k=*k-1;
	
	if(*k==0)
	{
		cout<<a[locn];
		exit(0);
	}
	find(a,k,n,locn*2);
	
}


  


int main()
{
	int n,k;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>k;
	
	find(a,&k,n,0);
}