#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int table[n+1][k+1];

    for(int i=0;i<=k;i++)
    {
        table[0][i]=0;
    }

    table[0][0]=1;

    for(int j=0;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            table[i][j]=table[i-1][j] || ((a[i-1]<=j)?table[i-1][j-a[i-1]]:0);
        }
    }

    cout<<table[n][k];



}