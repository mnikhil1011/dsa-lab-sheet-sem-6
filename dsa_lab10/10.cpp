#include<bits/stdc++.h>
using namespace std;

// u can use gfg one if u want it to be more simple
// this is O( klogk ) ig

int main()
{
    int n,k;
    cin >>n>>k;

    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    
    priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>> >q;


    
    set<pair<int,int>>s;
    int i=0,j=0;
    q.push({a[0][0],{0,0}});
    s.insert({0,0});

    for(int l=1;l<k;l++)
    {

        pair<int ,pair<int,int>>p=q.top();
        i=p.second.first;
        j=p.second.second;
        if(i+1<n)
        {
            if(s.find({i+1,j}) == s.end())
            {
                q.push({a[i+1][j],{i+1,j}});
                s.insert({i+1,j});
            }    

        }    
        if(j+1<n)    
        {
            if(s.find({i,j+1})== s.end())
            {
                q.push({a[i][j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        }    
        q.pop();
    }




    cout<<"ans"<<endl<<q.top().first;

}