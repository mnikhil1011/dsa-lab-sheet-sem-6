#include<bits/stdc++.h>
//check tc once, ig its just nlogn
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v1;
    vector<int>v2;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }

    map<int ,int>freq;

    for(auto itr:v1)
    {
        freq[itr]++;
    }
    
    for(auto itr:v2)
    {
        while(freq[itr])
        {
            freq[itr]--;
            cout<<itr<<" ";
        }
        freq.erase(itr);
    }

    for(auto itr:freq)
    {
        while(itr.second--)
            cout<<itr.first<<" ";
    }
}
