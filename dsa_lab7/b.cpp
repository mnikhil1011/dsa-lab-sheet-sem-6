#include<iostream>

using namespace std;

class node
{
	public:
		int val;
		node* left;
		node *right;
		
		node(int v)
		{
			val=v;
			left=NULL;
			right=NULL;
		}
};

int find(int* a,int x,int n)
{
	int i;
	for( i=0;i<=n;i++)
	{
		if(x==a[i])
			break;
	}
	return i;
}

node* buildtree(int *pre,int*in,int start,int end)
{
	static int here=0;
	
	if(start>end)
		return NULL;
	
	int val=pre[here];
	here++;	
		
	node * ptr=new node(val);	
	
	int index=find(in,val,end);
	
	if(start==end)
		return ptr;
	
	ptr->left=buildtree(pre,in,start,index-1);
	ptr->right=buildtree(pre,in,index+1,end);
	
	return ptr;
}

void printlvl(node * tree,int lvl)
{
	if(tree==NULL)
		cout<<-1<<" ";
	else if(lvl==0)
		cout<<tree->val<<" ";
	
	else
	{
			printlvl(tree->left,lvl-1);
			printlvl(tree->right,lvl-1);
	}	
}

int height(node* tree)
{
	if(tree==NULL)
		return 0;
	else
	{
		int lheight=height(tree->left);
		int rheight=height(tree->right);
		
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;		
	}	
}

void print(node* tree,int n)
{
	int h=height(tree);
	for(int i=0;i<h;i++)
	{
		printlvl(tree,i);
	}
	
	
}


int main()
{
	int n;
	cin>>n;
	int pre[n],in[n];
	for(int i=0;i<n;i++)
		cin>>pre[i];
		
	for(int i=0;i<n;i++)
		cin>>in[i];
		
	node* tree=buildtree(pre,in,0,n-1);
	print(tree,n);
	
		
}