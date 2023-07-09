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

node* makelist()
{
	int n;
	node * head=NULL;
	node * tail=NULL;
	scanf("%d",&n);
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

int findpos (int ans, node* head)
{
	node * tail=head;
	while(tail->next)
		tail=tail->next;
	while(head != tail)
	{
		int val=head->val+tail->val;
		if(val>ans)
		{
			tail=tail->prev;
		}
		else if(val<ans)
		{
			head=head->next;
		}
		else if(val ==ans)
			return 1;
	}
	return 0;
}


int main()
{
	int need;
	scanf("%d",&need);
	node * head= makelist();
	//printlist(head);
	int i=findpos(need,head);
	printf("%d",i);
	
	freelist(&head);

}