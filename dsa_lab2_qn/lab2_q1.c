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

float findmedian (node *head)
{
	int len=0;
	node *temp= head;
	node *temp2 = head;
	if(head== NULL)
		printf("no median");
	while(temp->next !=NULL && (temp->next)->next != NULL )
	{
		temp=temp->next;
		temp=temp->next;
		temp2=temp2->next;
	}
	if(temp->next == NULL)
	{
		
		return temp2->value;	
	}	
	
	float av=temp2->value ;
	temp2= temp2->next;
	av +=temp2->value;
	

	return av/2	;
}


int main()
{
	node* head=makelist();
	float median=findmedian(head);
	printf("%f", median);
	freelist(head);
}