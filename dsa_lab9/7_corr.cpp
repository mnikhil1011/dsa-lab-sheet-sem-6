#include<bits/stdc++.h>
//correct
//i didnt do this
using namespace std;

int better(int a, int b)   
{
    string s1=to_string(a);
    string s2=to_string(b);

    return s1+s2>s2+s1;
}
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n,better);

     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}