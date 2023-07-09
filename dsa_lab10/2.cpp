#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int i=0;
    int j=m-1;
    int ans;
    cin>>ans;
    while( i<n && j>=0)
    {
        if(a[i][j]==ans)
        {
            cout<<"yes";
            return 0;
        }
        else if(a[i][j]>ans)
            j--;
        
        else
            i++;
    }

    cout<<"no";
}