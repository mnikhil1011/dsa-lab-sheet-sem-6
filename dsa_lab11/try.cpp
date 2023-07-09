#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k,n;
    cin>>k>>n;
    vector<int>qn;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        qn.push_back(x);
    }
	//this im doing for k=5
    int one=0,two=0,ans=0;

	for(auto i:qn)
	{
		ans^=i;
		one=one^i & ~two;
		two=two^i & ~one;
	}
	cout<<" "<<ans<<" "<<one<<" "<<two;
	
    
}