#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node  *next;
	struct node  *prev;
};
typedef struct node node;

node* newnode()
{
	node * a= (node *) malloc(sizeof(node));
	a->next=NULL;
	a->prev=NULL;
	int val;
	scanf("%d",&val);
	a->val= val;
	return a;	
}

void addnode(node * head)
{
	while(head->next)
		head=head->next;
	
	node *a= newnode();
	head->next=a;
	a->prev=head;
}

node * makelist()
{
	int n;
	scanf("%d",&n);
	
	node * head =NULL;
	node * tail =NULL;
	n--;
	while(n)
	{
		n--;
		if(head == NULL)
		{
			head= newnode();
			tail= head;	
		}
		node * a= newnode();
		a->prev=tail;
		tail->next=a;
		tail=a;
	}
	return head;
}

void printlist(node * head)
{
	while(head)
	{
		printf("%d ",head->val);
		head=head->next;
	}
}

void freelist(node ** headref)
{
	node * head= *headref;
	while(head)
	{
		node * temp= head;
		head = head->next;
		free(temp);
		
	}
	*headref=NULL;
}

void fn1(node * head)
{
	addnode(head);
}

void fn2(node * head)
{
	printf("%d",head->val);
}

void fn3(node ** head)
{
	
	if((*head)->next==NULL)
		return;
	*head=(*head)->next	;
}

void fn4(node ** head)
{
	if((*head)->prev==NULL)
		return;
	(*head)=(*head)->prev;
}

node * findnode(node * head, int val)
{
	while( head != NULL)
	{
		if(head->val==val )
			return head;
		head=head->next;	
	}
	return NULL;
}

void fn6(node ** headref,node * here)
{
	node * head = * headref;
	int val;
	scanf("%d",&val);
	node * locn=findnode(head, val);
	node * a;
	if(locn==NULL)
	{
		a= (node *) malloc(sizeof(node));
		a->val= val;
	}
	else if( locn == here)
	{
		printf("we r in this song");
		return;
	}
	else if(locn->prev==NULL)
	{
		a= locn;
		*headref=(*headref)->next;
		(*headref)->prev=NULL;
	}
	else
	{
		a=locn;
		node *b=locn->prev;
		node *c= locn->next;
		b->next=c;
		if(c != NULL)
		c->prev=b;
	}
	node * b= here->next;
	here->next=a;
	a->prev=here;
	a->next=b;
	if(b != NULL)
	b->prev=a;
	
	
}

int main()
{
	node * head= makelist();
	node * locn=head;
	int k;
	do
	{
		scanf("%d",&k);
		switch(k)
		{
		
			case 1:
				fn1(locn);
				break;
			case 2:
				fn2(locn);
				break;
			case 3:
				fn3(&locn);
				break;
			case 4:
				fn4(&locn);
				break;	
			case 6:
				fn6(&head,locn);
				break;	
				
		}
		
		
	}while(k!= 5);


	freelist(&head);
	 
}