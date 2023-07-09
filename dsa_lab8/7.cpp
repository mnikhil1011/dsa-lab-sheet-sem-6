#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        pair<int,int> p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }
    int count=0;
    for(int i=0;i<n;i++ )
    {
        map<float,int>slope;
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;

            float sl=(float)(v[i].second-v[j].second)/(v[i].first-v[j].first);
           if(v[i].first==v[j].first && sl<0)
           {
                sl=-sl;
           }
              
            slope[sl]++;

        }
        int k=0;
        for(auto itr=slope.begin();itr != slope.end();itr++)
        {
            if( itr->second >1)
            {

                int z=(itr->second * (itr->second -1 ))/2;
                k+=z;
            }
        }
       
        count+=k;
        
    }
    int tot=n*(n-1)*(n-2)/6;
    int ans=tot-count/3;
    cout<<ans;
}