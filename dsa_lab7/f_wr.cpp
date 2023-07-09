
//this is wrong because this is nlogn, not nlogk


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int k;
	cin>>k;
	int n=0;
	vector<int>a;
	for(int i=0;i<k;i++)
	{
		int m;
		cin>>m;
		n+=m;
		for(int j=0;j<m;j++)
		{
			int x;
			cin>>x;
			a.push_back(x);
		}
	}
	
	priority_queue< int , vector<int> ,greater<int> >q (a.begin(),a.end());
	for(int i=0;i<n;i++)
	{
		cout<<q.top()<<" ";
		q.pop();
		
	}
	
	
}