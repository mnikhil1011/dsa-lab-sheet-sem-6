#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	stack<int> st;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(st.empty())
		{
			st.push(s[i]);
		}
		else if(s[i]==')' && st.top()=='(')
		{
			st.pop();
		}
		else
		{
			st.push(s[i]);
		}
	}
	
	cout<<st.size();
	
}