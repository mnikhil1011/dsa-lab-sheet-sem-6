#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n+1];
    int table[n+1][n+1];

    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
        table[i][i]=0;
    }
    n++;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<=n-l; i++)
        {
            int min=INT_MAX;
            int j=i+l-1;
            for(int k=i;k<j;k++)
            {
                int ans=table[i][k]+table[k+1][j]+a[i-1]*a[k]*a[j];
                if(ans<min)
                    min=ans;
            }
            table[i][j]=min;
        }
    }
    cout<<table[1][n-1];
}

