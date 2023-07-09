//for explaination  --  https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/   

#include<bits/stdc++.h>
using namespace std;


int main()
{
	vector<int>a;
	vector<int>b;
	int k,n;
	cin>>n>>k;
		
	for(int i=0;i<n;i++)
	{
	
		int x;
		cin>>x;
		a.push_back(x);
	}
	
	for(int i=0;i<n;i++)
	{
	
		int x;
		cin>>x;
		b.push_back(x);
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	priority_queue<pair<int,pair <int,int > > >q;

	q.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
	set<pair<int,int> >s;
	s.insert(make_pair(n-1,n-1));
	for(int i=0;i<k;i++)
	{
		pair<int,pair<int,int> >p=q.top();
		q.pop();
		
		cout<<p.first<<" ";
		int j=p.second.first;
		int k=p.second.first;
		p=make_pair(a[j]+b[k-1],make_pair(j,k-1));
		
		if(s.find(make_pair(j,k-1)) == s.end())
		{
			q.push(p);
			s.insert(make_pair(j,k-1));
		}
		
		p=make_pair(a[j-1]+b[k],make_pair(j-1,k));
		
		if(s.find(make_pair(j-1,k)) == s.end())
		{
			q.push(p);
			s.insert(make_pair(j-1,k));
		}
		
		
	}
		
}