#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    int n;
    cin>>n;
    int count =0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        auto itr=s.lower_bound(x);
        cout<<i<<" "<<distance(itr,s.end())<<endl;
        count+= distance(itr,s.end());
        s.insert(x);
    }
    cout<<endl<<count;
}

