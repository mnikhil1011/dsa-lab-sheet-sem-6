#include<bits/stdc++.h>
using namespace std;


int main()
{
    #define int long long int

    int n,q;
    cin>>n>>q;
    set<int>check;
    while(q--)
    {
        int x,k;
        cin>>x>>k;
        auto itr1=check.lower_bound(k);
        auto itr2=check.upper_bound(k);
        switch(x)
        {
                case 1:
                    if(check.find(k)==check.end())
                        check.insert(k);
                    else
                        check.erase(k); 

                       
                    break;
                case 2:
                    if(itr1==check.end())    
                        cout<<endl<<-1<<endl;
                    else
                        cout<<endl<<*itr1<<endl;
                    break;  

                case 3:   
                    if(check.empty() )
                       cout<<endl<<-1<<endl;
                    else if(itr2==check.end())   
                    {
                        auto itr2=check.rbegin();
                        cout<<endl<<*itr2<<endl;
                    } 
                    else if( *itr2>k)
                        cout<<endl<<-1<<endl;
                    else
                        cout<<endl<<*itr2<<endl;
                    break;    
        }



    }

    return 0;
}