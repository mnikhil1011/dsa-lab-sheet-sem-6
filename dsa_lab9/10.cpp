#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int> >q;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        pair<int,int>p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        while(!q.empty() && q.top()<v[i].first)
        {
            q.pop();
        }
        q.push(v[i].second);
        if(max<q.size())
            max=q.size();
    }

    cout<<max;
    
}