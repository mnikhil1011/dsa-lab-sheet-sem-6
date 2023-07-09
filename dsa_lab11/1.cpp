//only for small weights

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector< pair<int,int> >v;
    v.push_back({-1,-1});
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

   int table[n+1][k+1];

   for(int i=0;i<n+1;i++)
   {
       table[i][0]=0;              
   }
    for(int i=1;i<k+1;i++)
   {
       table[0][i]=0;              
   }

   

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<k+1;j++)
        {

            table[i][j]=table[i-1][j];
            if(v[i].first<=j)
            {
                table[i][j]=max(table[i][j],(table[i-1][j-v[i].first]+v[i].second));
            }

        }             
   }

   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<k+1;j++)
        {

            cout<<table[i][j]<<" ";

        }    
        cout<<endl;         
   }


   cout<<table[n][k];

}