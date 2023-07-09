#include<bits/stdc++.h>
using namespace std;

int conq(int* a, int l ,int m,int r)
{
    int lsum=0;
    int sum=0;
    for(int i=m;i>=l;i--)
    {
        sum+=a[i];
        lsum=max(lsum,sum);
    }
    int rsum=0;
     sum=0;
    for(int i=m+1;i<r;i++)
    {
        sum+=a[i];
        rsum=max(rsum,sum);
    }

    return lsum+rsum;
}

int div(int *a,int l,int r)
{
    while(l<r)
    {
        int m=(l+r)/2;
        int x=div(a,l,m);
        int y=div(a,m+1,r);
        int z=conq(a,l,m,r);
        return max(max(x,y),z);
    }

    return 0;
}

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    n--;
    cout<<div(a,0,n);

}