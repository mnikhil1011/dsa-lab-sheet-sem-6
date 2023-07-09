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

node* mergelist(node* a, node *b)
{
	node* mer=NULL;

	if(a== NULL)
	{
		mer=b;
		return;
	}
	if(b== NULL)
	{
		mer=a;
		return;
	}	
	if(a->value < b-> value)
	{
		mer=a;
		a=a->next;
	}
	else
	{
		mer=b;
		b=b->next;
	}
	node * ptr=mer;
	
	while(a!= NULL || b!= NULL)
	{
		if(a== NULL)
		{
			mer->next=b;
			break;
		}
		if(b== NULL)
		{
			mer->next=a;
			break;
		}
		
		if(a->value < b-> value)
		{
			mer->next=a;
			a=a->next;
		}
		else
		{
			mer->next=b;
			b=b->next;
		}
		
		mer=mer->next;

	}
	
	return ptr;
}

int main()
{
	node* head1=makelist();
	node * head2=makelist();
	node *merged=mergelist(head1,head2);
	printlist(merged);
}