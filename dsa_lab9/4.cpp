#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x-k);
    }

    int prefix[n+1];
    prefix[0]=0;
    map<int,int>freq;
    freq[0]++;
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+v[i-1];
        freq[prefix[i]]++;
    }
    int ans=0;
    for(auto itr:freq)
    {
        if(itr.second>1)
            ans+=(itr.second)*(itr.second-1)/2;
    }
    cout<<ans;
}