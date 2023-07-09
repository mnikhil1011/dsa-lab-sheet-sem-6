#include<bits/stdc++.h>
using namespace std;


void rev(vector<int>& v,int k)
{
    int l=0;

    while(l<k)
    {
        int temp=v[l];
        v[l]=v[k];
        v[k]=temp;
        k--;
        l++;
    }
}
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
    
    int count=0;
    vector<int>ans;
    for(int i=n-1;i>0;i--)
    {
        int locn=0;
        for(int j=1;j<=i;j++)
        {
            if(v[locn]<v[j])
                locn=j; 
        }

        if(locn == i)
            continue;
        else if( locn!= 0)
        {
            count++;
            ans.push_back(locn);
            rev(v,locn);

        } 
        count++;
        ans.push_back(i);
        rev(v,i);  
    }

    cout<<endl<<count<<endl;

    for(int i=0;i<count;i++)
    {
        cout<<ans[i]+1<<" ";
    }

    
}