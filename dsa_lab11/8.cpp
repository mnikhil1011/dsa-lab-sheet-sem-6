#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int maxm=0;
    int base=0;
    stack<int>stk;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            stk.push(i);
        else
        {
            if(!stk.empty())
            {
                stk.pop();
                int a=(stk.empty())?base:stk.top();
                int ans=i-a;
                maxm=max(maxm,ans);
            }
            else
            {
                base=i;
            }
        }
    }

    cout<<maxm;

}