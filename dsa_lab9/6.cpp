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
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    deque<int>q;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(q.empty())
            q.push_back(v[i]);
        else
        {
            if(q.front()+k <=v[i])
            {
                ans++;
                q.pop_front();

            }
            else
            {
                q.push_back(v[i]);
            }
        }
    }
    cout<<ans;
}