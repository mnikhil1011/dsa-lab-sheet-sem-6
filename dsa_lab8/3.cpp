#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>v;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int x,y;
    cin>>x;
    cin>>y;
    map <int,int > m;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int p=v[i]-(x)*i;
        int q= v[i]-(y)*i;
        count+=m[q];
        m[p]++;
    }
    cout<<count;

}