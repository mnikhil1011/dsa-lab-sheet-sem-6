#include<bits/stdc++.h>
//check tc once, ig its just nlogn
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v1;
    vector<int>v2;
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        sum1+=x;
        v1.push_back(x);
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        sum2+=x;
        v2.push_back(x);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    int ans=sum1-sum2;
    int i=0;
    int j=0;
    if(ans==0)
    {
        cout<<"yes";
        return 0;
    }
    while( i<n && j<m)
    {
        int see =ans+ 2*v2[j]-2*v1[i];
        if(see==0)
        {
            cout<<"yes"<<" "<<v1[i]<<" "<<v2[j];
            return 0;
        }
        else if(see>0)
        {
            i++;
        }
        else
        {
            j++;
        }



    }

    cout<<"no";

}
