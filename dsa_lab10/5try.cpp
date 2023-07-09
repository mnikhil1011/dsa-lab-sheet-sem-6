#include<bits/stdc++.h>
using namespace std;

int better(pair<int,int>p,pair<int,int>q)
{
    if(p.first == q.first)
    {
        return p.second>q.second;
    }
    return p.first>q.first;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int> >v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;
        v.push_back({x,y});
    }

    sort(v.begin(),v.end(),better);

    int count=1;
    int locnl=0;
    int locnr=0;
    for(int i=1;i<n;i++)
    {
        if(v[locnr].second>v[i].second)
        {
            locnr=i;
        }
        if(v[locnl].first >v[i].first && v[locnl].second>v[i].second)
        {
            count++;
            locnl=i;
        }
        if(v[locnl].first >v[i].first && v[locnl].second>v[i].second)
        {
            count++;
            locnr=i;
        }
        
    }

    cout<<count;

}