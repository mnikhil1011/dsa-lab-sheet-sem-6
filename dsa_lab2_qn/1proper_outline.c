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
	node *n= malloc(sizeof(node));
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



void printnode(node * head)
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

void freelist(node ** headptr)
{
	node * head=*headptr;
	node *ptr= head;
	while(ptr !=NULL)
	{
		head=ptr;
		ptr=ptr->next;
		free(head);
	}
	*headptr=NULL;
}


int main()
{
	node* head=makelist();
    
    freelist(&head);
}