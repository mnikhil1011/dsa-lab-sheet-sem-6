#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
     
    priority_queue<int,vector<int>,greater<int>> q;
    int max=0;
    int happy=0;
    for(int i=0;i<n;i++)
    {
        q.push(v[i]);
        happy+=v[i];

        if(happy <0)
        {
            happy -= q.top();
            q.pop();
        }

        if(max<q.size())
            max=q.size();

    }

    cout<<max;

}