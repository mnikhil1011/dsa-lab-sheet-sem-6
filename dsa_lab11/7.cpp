#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s1;
    cin>>s1;
    n=s1.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int count=0;

    for(size_t i=0;i<n;i++)
    {
        dp[i][i]=1;
        count++;
    }
    for (size_t k =1; k< n; k++)
    {
        for (size_t i =0; i<n-k; i++)
        {
            int j=i+k;

            if(s1[i]==s1[j])
            {
                if(k==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i+1][j-1] ;  
            }

            if(dp[i][j]==1)
                count++;

        }
    }
    
    cout<<count;
    
}