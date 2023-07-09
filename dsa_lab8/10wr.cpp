#include<bits/stdc++.h>
using namespace std;


//idk if this is what they want

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int ptr1=0 ,ptr2=0,count=0;
		
	while(ptr2<n)
	{
		if(a[ptr2]==1)
			k--;
		
		while(k<0)
		{
			if(a[ptr1++]==1)
				k++;
		}	
		count+=ptr2-ptr1+1;
		ptr2++;	
	}
	cout<<count;		
}