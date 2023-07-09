#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int table[k+1];
    table[0]=0;

    for(int i=1;i<=k;i++)
    {
        int minm=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(a[j]>i || table[i-a[j]]==INT_MAX)
                continue;

            int temp=table[i-a[j]]+1;
            minm=min(minm,temp);
        }
        table[i]=minm;
    }
    if(table[k]==INT_MAX)
    {
        cout<<-1;
        return 0;
    }
    cout<<table[k];

}