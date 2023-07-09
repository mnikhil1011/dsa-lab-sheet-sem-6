#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	int val;
	struct node* prev;
	struct node * next;
};
typedef struct node node;

node * makenode()
{
	int val;
	scanf("%d",&val);
	node * a=(node*)malloc(sizeof(node));
	a->val=val;
	a->next=NULL;
	a->prev=NULL;
	return a;
}

node * makelist()
{
	node * head=NULL;
	node * tail=NULL;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		if(head==NULL)
		{
			tail=makenode();
			head=tail;
			continue;		
		}			
		node * a=makenode();
		a->prev=tail;
		tail->next=a;
		tail=a;
	}
	return head;
}

void printlist(node* head)
{
	while(head != NULL)
	{
		printf("%d ",head->val);
		head=head->next;
	}
}

void freelist(node** headref)
{
	node * head=*headref;
	while(head)
	{
		node * a=head;
		head=head->next;
		free(a);
	}
	*headref=NULL;
}

void maketeam(node* head)
{
	node * tail= head;
	while(tail->next)
		tail=tail->next;
	
	long hval=head->val;
	long tval= tail->val;
	int h=1,t=1;
	int ah,at;
	
	while( head!= tail)
	{
		if(hval==tval)
		{
			ah=h;
			at=t;
		}
		else if(hval>tval)
		{
			tail=tail->prev;
			tval=tval+tail->val;
			t++;
			continue;
		}
		head=head->next;
		hval=hval+head->val;
		h++;
	}
	
	printf("\n %d %d",ah,at);
		
}

int main()
{
	node * head= makelist();
	//printlist(head);
	//freelist(&head);
	maketeam(head);
}