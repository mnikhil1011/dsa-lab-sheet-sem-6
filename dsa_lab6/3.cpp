#include<stack>
#include<iostream>

using namespace std;

int main()
{
	stack <int>s;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int max=-1;
	for(int i=0;i<n;i++)
	{
		if(s.empty() || a[i]>=a[s.top()])
		{
			s.push(i);
		}
		else
		{
			while(!s.empty() && a[i]<a[s.top()])
			{
				int k=s.top(); 
				s.pop();
				int area;
				if(!s.empty())
					area=a[k]*(i-s.top()-1);
				 else
				 	area=a[k]*i;
				if(area>max)
					max=area;
			}
			s.push(i);
		}
	}
	while(!s.empty()) 
	{
		int k=s.top(); 
		s.pop();
		int area;
		if(!s.empty())
			area=a[k]*(n-s.top()-1);
			
		else
			area=a[k]*(n);
			
			
		if(area>max)
			max=area;	
	}
	
	printf("%d",max);	
	
}