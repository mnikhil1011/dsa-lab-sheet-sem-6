
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    string s1,s2;
    cin>>n;
    cin>>s1;
    cin>>m;
    cin>>s2;

    int table[n+1][m+1];
    table[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        table[i][0]=i;
    }
    for(int i=0;i<=m;i++)
    {
        table[0][i]=i;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1];
            }
            else
            {
               table[i][j]= min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]))+1;
            }
        }
    }

    cout<<table[n][m];

}