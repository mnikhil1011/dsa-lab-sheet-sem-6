#include<bits/stdc++.h>

using namespace std;
int better(int a, int b)
{
    string s1=to_string(a);
    string s2=to_string(b);

    return s1+s2>s2+s1;
}

void con(int* a,int start,int mid,int end)
{
    vector<int>v1;
    vector<int>v2;
    int p=mid+1-start;
    int q=end-mid;
    for(int i=0;i<p;i++)
        v1.push_back(a[i+start]);
    for(int i=0;i<q;i++)
        v2.push_back(a[i+mid+1]);
    int i=start;
    int j=0,k=0;
    while(j<p && k<q)
    {
        if(better(v1[j],v2[k]))
            a[i++]=v1[j++];
        
        else
            a[i++]=v2[k++];
        
    }
    while(j<p)
        a[i++]=v1[j++];
    while(k<q)
        a[i++]=v2[k++];
}

void div(int* a,int start,int n)
{
    if(n>start)
    {
        int mid=(start+n)/2;
        div(a,start,mid);
        div(a,mid+1,n);      
        con(a,start,mid,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];

    div(a,1,n);

     for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}