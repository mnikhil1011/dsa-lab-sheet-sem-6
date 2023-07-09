#include<iostream>

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
	if(i<=n)
	{
		temp=new node(a[i]);
		temp->left=maketree(a,n,2*i);
		temp->right=maketree(a,n,2*i+1);
	}
	return temp;
		
}

node* correct(node* tree,int min,int max)
{
	if(tree==NULL)
		return NULL;
		
	tree->left=correct(tree->left,min,max);
	tree->right=correct(tree->right,min,max);
	
	if(tree->val<min)
	{
		return tree->right;
	}
	else if(tree->val>max)
	{
		return tree->left;
	}
	return tree;
}

void print(node* a)
{
	if(a==NULL)
		return;
	print(a->left);
	print(a->right);
	cout<<a->val<<" ";
	
}

int main()
{
	int n,l,r;
	cin>>n>>l>>r;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	
	node* tree=maketree(a,n,1);
		
	node * cor=correct(tree,l,r);
	
	print(cor);	
		
		
}

