#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],ans[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans[i]=-1;
	}
	
	stack <int>s;
	
	for(int i=2*n-1;i>=0;i--)	
	{
		while(!s.empty() && a[s.top()]<=a[i%n])
		{
			s.pop();
		}
		
		if(i<n && !s.empty())
		{
			ans[i]=s.top()-i ;
			if(ans[i]<0)
			{
				ans[i]+=n;
			}
		}
		s.push(i%n);

	}
	
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}		
}