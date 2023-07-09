#include<bits/stdc++.h>
//even this idk
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a;

    for(size_t i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
        dp[i][i]=a[i];
    }
    for (size_t l = 2; l<=n; l++)
    {
        for (size_t i = 0; i <= n-l; i++)
        {
            int j=i+l-1;

            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
        
    }

    int v=dp[0][n-1];
    if(v>0)
    {
        cout<<"v";
    }
    else
    {
        cout<<"o";
    }
    
    cout<<endl<<v;


}