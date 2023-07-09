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

    deque<int>q;

    for(int i=0;i<n;i++)
    {
        while(!q.empty() && v[q.front()]<v[i])
            q.pop_front();
        q.push_back(i);
        if(q.front()+k <= i) 
            q.pop_front(); 
        if(i>=k-1)
            cout<<v[q.front()];
        
    }
}















