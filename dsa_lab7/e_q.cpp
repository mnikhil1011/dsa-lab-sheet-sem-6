#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,k;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	priority_queue <int>q(a,a+n);
	
	for(int i=1;i<k;i++)
	{
		q.pop();
	}
	cout<<q.top();
	
	
	
	
}