#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	priority_queue<int> q(a,a+n);
	
	for(int i=0;i<m;i++)
	{
		int x=q.top();
		q.pop();
		x /=2;
		q.push(x);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans;
		
		
}