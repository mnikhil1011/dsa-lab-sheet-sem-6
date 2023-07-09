#include<stdio.h>
#include<iostream>

using namespace std;

class minstack
{
	int a[1000];
	int min;
	int top;
	public:
	minstack()
	{
		int n;
		cin>>n;
		top=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(i==0)
				min=x;
			push(x);
		}
	}
	void push(int x)
	{
		if(x>=min)
		{
			a[top]=x;
			top++;
			return;
		}
		a[top]=2*x-min;
		top++;
		min=x;
	}
	void pop()
	{
		top--;
		if(a[top]<min)
		{
			min=2*min-a[top];
		}
	}
	int tope()
	{
		if(a[top-1]<min)
		{
			return min;
		}
		return a[top-1];
	}
	
	int getmin()
	{
		return min;
	}
	
};

int main()
{
	
	minstack s;
	int n;

	cin>>n;
	while(n--)
	{
		int i;
		cin>>i;
		
		switch(i)
		{
			case 1:
				int x;
				cin>>x;
				s.push(x);
				break;
			case 2:
				s.pop();
				break;	
			case 3:
				cout<<"    "<<s.tope()<<endl;
				break;
			case 4:
				cout<<"    "<<s.getmin()<<endl;	
				break;	
		}
				
	}
}