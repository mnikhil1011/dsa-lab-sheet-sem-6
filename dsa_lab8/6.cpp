#include<bits/stdc++.h>
using namespace std;

// can use unordered map to make it possible in On but worst case in unordered map n2

int main()
{
	int n;
	cin>>n;
	int a[n];
	map <int,int>freq;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	int prefix[n+1];
	for(int i=0;i<=n;i++)
	{
		if(i==0)
			prefix[i]=0;
		else
			prefix[i]=prefix[i-1]^a[i-1];		

		freq[prefix[i]]++;
	}
	
	int ans=0;
	for(auto ptr=freq.begin();ptr!=freq.end();ptr++)
	{
		if(ptr->second >1)
			ans+= ptr->second*(ptr->second-1)/2;
	}
	
	cout<<ans;	
}