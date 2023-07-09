#include<bits/stdc++.h>

using namespace std;

// test it with more test cases (mostly correct but there might be some small error)

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
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[i]-=x;
    }

    deque<int>q;
    int sum=0;
    cout<<endl;
    for(int i=0;i<2*n;i++)
    { 
        if(!q.empty() &&  q.front()==i%n && sum>=0)
        {
            cout<<i%n;
            return 0;
        }
        q.push_back(i%n);
        sum+=v[q.back()];
        while(!q.empty() && sum<0)
        {
            sum-=v[q.front()];
            q.pop_front();
            
        }  
         
    }
    cout<<-1;

}