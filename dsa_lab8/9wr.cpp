#include<bits/stdc++.h>

using namespace std;
//it is gaurnteed every player plays a match hence k=O(n)
int main()
{
    int n,k;
    map<int,int>freq;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cin>>x;
        freq[x]++;
    }
    for(int i=1;i<=k;i++)
        if(freq[i]<2)
            cout<<i<<" ";
}