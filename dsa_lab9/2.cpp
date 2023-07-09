#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    int prefix[n+1] ;
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='*')
             prefix[i]=prefix[i-1]+1;
        else
            prefix[i]=prefix[i-1];
    }
    vector<pair<int,int> >v;
    int locn=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='|')
            locn=i;
        
        v.push_back({locn,-1});
    }
    locn=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='|')
            locn=i;
        
        v[i].second=locn;
    }
    int ans[q];
    for(int i=0;i<q;i++)
    {
        pair<int,int>p;
        cin>>p.first>>p.second;
        int k=v[p.first].second;
        int l=v[p.second].first;
        if(l==-1 || k==-1)
        {
            ans[i]=-1;
            continue;
        }

        ans[i] = prefix[l]- prefix[k];

    }

    for(int i=0;i<q;i++)
    {
        if(ans[i]<0)
            cout<<0;
        else    
            cout<<ans[i]<<endl;
    }

    
}