#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    int b[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }

    int table[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        table[0][i]=0;
    }
    int maxm=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=0;
            }
            maxm=max(maxm,table[i][j]);
        }
    }

    cout<<maxm;


    

    
}