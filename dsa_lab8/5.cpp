#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,m;
    cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    map<int,int>freq;
    set<int>s;
    int i=0;
    for(;i<m;i++)
    {
        freq[a[i]]++;
        if(freq[a[i]]==k)
            s.insert(a[i]); 
        else
             s.erase(a[i]);
    }
    for(;;i++)
    {   
        if(s.empty())
            cout<<-1<<endl;
        else
        {
            cout<<*s.rbegin() <<endl;
        }                
        if(i==n)
            return 0;

        freq[a[i-m]]--;
        freq[a[i]]++;
        if(freq[a[i]]==k)
            s.insert(a[i]);
        else
             s.erase(a[i]);

        if(freq[a[i-m]]==k)
            s.insert(a[i-m]);
        else
             s.erase(a[i-m]);

    }
}