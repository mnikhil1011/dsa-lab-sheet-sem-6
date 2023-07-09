#include<iostream>
#include<vector>

using namespace std;

class node
{
	public :
		int val;
		node* left;
		node* right;
		
		node(int v)
		{
			val=v;
			left=NULL;
			right=NULL;
		}
		
};

node* maketree(int*a,int n,int i)
{
	node * temp=NULL;
	if(i<=n && a[i]!=-1)
	{
		temp=new node(a[i]);
		temp->left=maketree(a,n,2*i);
		temp->right=maketree(a,n,2*i+1);
	}
	return temp;
		
}

int path(vector<int>&p,int x,node* head)
{

	if(head==NULL)
		return 0;
	p.push_back(head->val);			
	if(head->val==x)
		return 1;
	if( path(p,x,head->left))
		return 1;
		
	else if( path(p,x,head->right))
		return 1;	
			
	else
	{
		p.pop_back();
		return 0;
	}
			
}



int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	node* tree=maketree(a,n,1);
	//print(tree);
	vector<int>path1;
	vector<int>path2;
	path(path1,x,tree);
	path(path2,y,tree);
	int i=0,j=0;
	
	while(path1[i]==path2[i])
		i++;
	
	cout<<path1[i-1];	

		
}

