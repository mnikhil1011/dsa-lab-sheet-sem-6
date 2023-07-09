//not complete;
#include<bits/stdc++.h>

using namespace std;

void strev(string & s,int n)
{
    int l=0;
    while(l<n)
    {
        int temp=s[l];
        s[l]=s[n];
        s[n]=temp;
        n--;
        l++;
    }
}

int main()
{
    int n;
    string s1,s2;
    cin>>s1;
    n=s1.length();
    cout<<n<<endl;
    s2=s1;
   strev(s2,n-1);

    int table[n+1][n+1];
    table[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        table[0][i]=0;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
               table[i][j]=0;
            }

        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<table[i][j]<<" ";
            
        }
        cout<<"\n";
    }

}