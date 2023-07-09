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

void revlist(node** slow)
{
	node* curr= * slow;
	node * prev= NULL;
	node * next =NULL;

	while(curr->next !=NULL)
	{
		next =curr->next;
		curr->next = prev;
		prev= curr;
		curr= next;
	}
	curr -> next = prev;
	*slow =curr;

}
int ispallendrome(node* head)
{
	node * fast=head;
	node * slow=head;
	
	while( fast != NULL && fast -> next != NULL  )
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	if(fast != NULL)
		slow = slow->next;
	revlist(&slow);
	while(slow != NULL)
	{
		if(slow->value != head ->value)
			return 0;
		slow=slow->next;
		head=head->next;	
	}
	return 1;
}

int main()
{
	node* head=makelist();
	int x=ispallendrome( head);
	printf("%d", x);
	
	
	freelist(head);
}