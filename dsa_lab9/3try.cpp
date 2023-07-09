#include<bits/stdc++.h>
//couldnt do this on my own
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

    stack<int>s;

    int ans=0;

    for(int i=0;i<n;i++)
    {

        while(!s.empty() && v[i]>v[s.top()])
        {
            int top=s.top();
            s.pop();
            if(!s.empty())
                ans+= v[top]*(top-s.top())*(i-top);
            else  
                ans+=v[top]*(top+1)*(i-top);
        }
        s.push(i);
    }

    while(!s.empty() )
    {
        int i=n;
        int top=s.top();
        s.pop();
        if(!s.empty())
            ans+= v[top]*(top-s.top())*(i-top);
        else  
            ans+=v[top]*(top+1)*(i-top);
    }
       
    s=stack<int>();

    for(int i=0;i<n;i++)
    {

        while(!s.empty() &&v[i]<v[s.top()])
        {
            int top=s.top();
            s.pop();
            if(!s.empty())
                ans-= v[top]*(top-s.top())*(i-top);
            else  
                ans-=v[top]*(top+1)*(i-top);
        }
        s.push(i);
    }

    while(!s.empty() )
    {
        int i=n;
        int top=s.top();
        s.pop();
        if(!s.empty())
            ans-= v[top]*(top-s.top())*(i-top);
        else  
            ans-=v[top]*(top+1)*(i-top);
    }



    cout<<ans;

}


