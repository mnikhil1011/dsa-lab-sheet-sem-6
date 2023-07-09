//didnt get on my own

#include<bits/stdc++.h>
using namespace std;

int check(vector<int>v,int mid,int k,int n)
{
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>mid)
            return 0;
        sum+=v[i];
        if(sum>mid)
        {
            sum=v[i];
            count++;
        }
    }
    count++;
    if(count<=k)
    {
        return 1;
    }
    else
        return 0;
}




int binsearch(int start,int end,int n,vector<int>v,int k )
{
    int ans;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(check(v,mid,k,n))
        {
            ans=mid;    
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}

int main()
{
    int n;
    int k;
    cin>>n>>k;
    vector<int>v;
    int page=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        page+=x;
    }
    cout<<binsearch(0,page,n,v,k);
}