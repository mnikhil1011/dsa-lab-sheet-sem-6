//this is what they want(doesnt work for big values but works for big weights);
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector< pair<int,int> >v;
    int m=0;
    v.push_back({-1,-1});
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
        m+=y;
    }

   int table[n+1][m+1];

   for(int i=0;i<n+1;i++)
   {
       table[i][0]=0;              
   }
    for(int i=1;i<m+1;i++)
   {
       table[0][i]=1000000;              
   }

   

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<m+1;j++)
        {
            table[i][j]=table[i-1][j];
            if(v[i].second <= j )
            {
                    table[i][j]=min(table[i][j],table[i-1][j-v[i].second]+v[i].first);
            }
        }             
   }

          
    for(int i=m;i>=0;i--)
    {
        if(table[n][i]<=k)
        {
            cout<<i;
            return 0;
        }
    }

}