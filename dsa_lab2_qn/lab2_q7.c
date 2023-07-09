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
		printf("%d",head->value);
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

node* remrep(node* head)
{
	node * ans= head;
	while(head->next != NULL )
	{
		if(head->next->next==NULL)
			break;
		node * temp = head->next->next;
		if(head-> next->value != temp->value)
		{
			head=head->next;
			continue;
		}
		
		while(temp != NULL)
		{
			if( head->next->value ==temp->value )
				temp=temp->next;
			else
				break;	
			
		}
		head->next =temp;
		head=head->next;
	}
	
	return ans;
	
}

int main()
{
	node* head=makelist();
	node* newnode =remrep(head);
	printlist(newnode);
	freelist(head);
}