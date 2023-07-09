#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	priority_queue<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push(x);
	}
	int ans=0;
	for(int i=0;i<k;i++)
	{
		ans +=a.top()/2;
		if(a.top()%2==1)
			ans+=1;
		int x=a.top();
		a.pop();
		a.push(x/2);
	}
	
	cout<<ans;
	
		
		
}