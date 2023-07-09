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

node * revlist(node * head)
{
	node * cur=head;
	node * prev =NULL;
	node * next= NULL;
	while(cur->next != NULL)
	{
		next= cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	cur->next=prev;
	return cur;
}

int main()
{
	node* head=makelist();
	head =revlist(head);
	printlist(head);
	freelist(head);
}