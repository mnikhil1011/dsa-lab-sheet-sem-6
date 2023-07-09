#include<iostream>
#include<vector>
//this is correct nlogk
using namespace std;

vector<int> merge(vector<int>v1,vector<int>v2)
{
	vector<int>ans;
	int i=0,j=0;
	int x=v1.size();
	int y=v2.size();
	while(x>i && y>j)
	{
		if(v1[i]<v2[j])
		{
			ans.push_back(v1[i]);
			i++;
		}
		else
		{
			ans.push_back(v2[j]);
			j++;
		}
	}
	
	while(x>i)
	{
		ans.push_back(v1[i]);
		i++;
	}
	while(y>j)
	{
		ans.push_back(v2[j]);
		j++;
	}
	
	return ans;
}

int main()
{
	int k;
	cin>>k;
	
	vector<int>v[k];
	
	int size[k];
	for(int i=0;i<k;i++)
	{
		cin>>size[i];
		for(int j=0;j<size[i];j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	
	for(int i=k/2;i>0;i/=2)
	{
		for(int j=0;j<i;j++)
		{
			v[j]=merge(v[j],v[j+i]);
		}
	}
	
	int n=v[0].size();
	for(int i=0;i<n;i++)
		cout<<v[0][i]<<" ";
	
}