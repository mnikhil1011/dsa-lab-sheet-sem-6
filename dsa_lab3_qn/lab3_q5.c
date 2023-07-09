#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node* next;
	struct node* prev;
};
typedef struct node node;

node * makenode()
{
	node* a = (node*)malloc(sizeof(node));
	int val;
	scanf("%d",&val);
	a->val=val;
	a->next=NULL;
	a->prev=NULL;
	return a;
}

node* makelist(int n)
{
	node * head=NULL;
	node * tail=NULL;
	while(n--)
	{
		node * a=makenode();
		if(head==NULL)
		{
			head=a;
			tail=head;
			continue;
		}
		tail->next=a;
		a->prev=tail;
		tail=a;
		
	}
	
	return head;
	
}

void printlist(node * head)
{
	while(head)
	{
		printf("%d ", head->val);
		head=head->next;
	}
}

void freelist(node ** headref)
{
	node * head= * headref;
	while(head)
	{
		node * temp= head;
		head=head->next;
		free(temp);
	}
	*headref=NULL;
}

void rotatelist (int ans, node** headref)
{
	node * head= *headref;
	node * tail=head;
	while(tail->next)
		tail=tail->next;
	tail->next=head;
	head->prev=tail;

	while(ans--)
		head=head->prev;
	tail=head->prev;
	tail->next=NULL;
	head->prev=NULL;
	*headref=head;		
}


int main()
{
	int need;
	int n;
	scanf("%d%d",&n,&need);
	node * head= makelist(n);
	rotatelist(need,&head);
	printlist(head);
	freelist(&head);

}