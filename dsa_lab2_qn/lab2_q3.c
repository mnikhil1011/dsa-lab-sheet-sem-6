#include<stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
};
typedef struct node node;

node* makenode( int val)
{
	node *n=(node *) malloc(sizeof(node));
	n->value=val;
	n->next=NULL;
	return n;
}

node* addnode(node* head,int val)
{
	node* newnode = makenode(val);
	
	if(head==NULL)
	{
		return newnode;
	}
	node *temp=head;
	while(temp->next != NULL)
		temp=temp->next;
	
	temp->next=newnode;	
	return;
}

node* makelist()
{
	int n;
	node* head=NULL;
	scanf("%d",&n);
	int i=0;
	for(;i<n;i++)
	{
		int val;
		scanf("%d",&val);
		if(head==NULL)
		head =addnode(head,val);
		else
		addnode(head,val);
	}
	return head;
	
}

void printlist(node * head)
{
	if(head== NULL)
	{
		printf("no node");
		return;
	}
	while(head)
	{
		printf("%d ",head->value);
		head=head->next;
	}
		
}

void freelist(node* head)
{
	node *ptr= head;
	while(head)
	{
		ptr=head;
		head=head->next;
		free(ptr);
	}
}

node* changelist(node * head, int del)
{
	node* ans= head;
	int len =1;
	while(head->next)
	{
		len++;
		head=head->next;
	}
	len=len-del;
	int i;
	head= ans;
	for(i=0;i<len-1;i++)
	{
		head=head->next;
	}
	node* a= head->next;
	head->next=head->next->next;
	free(a);
	return ans;
}

// not efficient make it better using merge
 
node* sortlist(node * head)
{
	node * ans= head;
	int count =1;
	while(head ->next)
	{
		head= head->next;
		count++;
	}
	int len= count;
	while(count)
	{
		node* temp = ans;
		node * prev= NULL;
		while(temp->next)
		{
			if(temp->value >temp->next->value)
			{
				node * a= temp->next->next;
				node*b= temp->next;
				if(prev != NULL)
				{
					prev->next= temp->next;
					prev=prev->next;

				}
				else
				{
					ans=temp->next;
				}				
				temp->next->next=temp;
				temp->next=a;
				temp= b;
				}
			else
			{
				prev=temp;
				temp=temp->next;
			}
		}
		count--;
		
		
	}


	return ans;
}
int main()
{
	node* head=makelist();
	node* sorted= sortlist(head);
	printlist(sorted);
	freelist(sorted);
	
}