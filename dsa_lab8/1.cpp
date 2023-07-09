#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }

    map<string,int>freq;
    
    for(int i=0;i<n;i++)
    {
        int freq2[26]={};
        for(int j=0; j<v[i].length();j++)
        {
            freq2[v[i][j]-'a']++;
        }
        string s;
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<freq2[j];k++)
            {
                s.push_back((char)(j+'a'));
            }

        }
        freq[s]++;
    }
    int ans=0;
    for(auto itr=freq.begin();itr !=freq.end();itr++)
    {
        if(itr->second>1)
        {
            ans += itr->second * (itr->second-1)/2;
        }
    }
    cout<<ans;
}