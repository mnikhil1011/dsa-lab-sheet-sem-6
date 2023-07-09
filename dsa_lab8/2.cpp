#include<bits/stdc++.h>

using namespace std;

void mirror(vector<int>&v,int i,int j)
{
	while(i>=0)
	{
		v[j]=v[i];
		j++;
		i--;
	}
}

void print(vector<int>v,int n)
{
	for(int i=0;i<n;i++)
	{
		
		cout<<v[i];
	}
}

void correct(vector<int>&v,int n,int l)
{
	while(l>=0)
	{
		if(v[l]==10)
		{
			v[l]=0;
			v[--l]++;
		}
		else
			break;
	}
}

int checknine(int x)
{
	while(x)
	{
		if(x%10 != 9)
			return 0;
		x=x/10;	
	}
	return 1;
}

void printbig(int n)
{
	for(int i=0;i<n;i++)
	{
		if(i==0 || i==n-1)
			cout<<1;
		else
			cout<<0;	
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int>v;
	int x;
	cin>>x;
	if(checknine(x)==1)
	{
		printbig(n+1);
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		int y;
		y=x/pow(10,n-i-1);
		y=y%10;
		v.push_back(y);
	}
	
	int midl=n/2;
	int midr=n/2;
	if(n%2==0)
		midl--;
	
	vector<int>ans=v;
	mirror(v,midl,midr);
	
	int i=0;
	for(;i<n;i++)
	{
		if(v[i]!=ans[i])
			break;
	}
	
	if(i<n && v[i]>ans[i])
		print(v,n);
	else
	{
		v[midl]++;
		correct(v,n,midl);
		mirror(v,midl,midr);
		print(v,n);	
	}	
}