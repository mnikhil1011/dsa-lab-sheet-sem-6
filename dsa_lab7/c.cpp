#include<iostream>

using namespace std;

int check(int*a,int n,int locn,int sum,int*ans,int need)
{
	
	if(locn>n || a[locn]==-1)
	{
		if(sum==need)
		{
			*ans=*ans+1;
		}
	}
	else
	{
		check(a,n,locn*2,sum+a[locn],ans,need);
		check(a,n,locn*2+1,sum+a[locn],ans,need);
	}
	
}

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	check(a,n,1,0,&ans,k);
		
	cout<<ans/2;	
}