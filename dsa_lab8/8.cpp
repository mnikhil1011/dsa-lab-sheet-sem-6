#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();

    map<string,int>freq;
    int count=0;
    for(int i=0;i<n-10;i++)
    {
        string str=s.substr(i,10);
        freq[str]++;
        if(freq[str]==2)
            count++;
    }
    cout<<count<<endl;
    for(auto itr=freq.begin();itr!= freq.end();itr++)
    {
        if(itr->second>1)
            cout<<itr->first<<endl;  
    }

}