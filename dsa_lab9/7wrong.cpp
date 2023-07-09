#include<bits/stdc++.h>

using namespace std;
//wrong tc
int better(int a, int b)   
{
    string s1=to_string(a);
    string s2=to_string(b);

    int i=0;
    while(i<s1.length() && i<s2.length())
    {
        if(s1[i]==s2[i])
        {
            i++;
            continue;
        }
        return s1[i]>s2[i];    
    }
    if(i==s1.length())
    {
        return s2[s1.length()]<s2[s1.length()-1];
    }
    else
        return s1[s2.length()]>s1[s2.length()-1];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n,better);

     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}