#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * link;
};
struct node *head = NULL, *tail= NULL, *cur, *prev, *next;
void create()
{
	int n,i;
	printf(" enter number of nodes :  \n");
	scanf("%d",&n);
	for(i = 0;i<4;i++)
	{	
		
		cur =(struct node*)malloc(sizeof(struct node));
		printf("enter current node data \n");
		scanf("%d",&(cur->data));
		cur->link = NULL;
		if(head==NULL)
		{
			head = tail = cur;
		}
		else
		{
			tail->link=cur;
			tail=cur;
		}
	}
}

void insert_atbegin()
{
	cur = (struct node*)malloc(sizeof(struct node));  
	printf("enter data");
	scanf("%d",&(cur->data));
	cur->link = head;
	head = cur;
}
void insert_atpos()
{
	int pos,c=1;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(cur->data));
	printf("Enter position at which data should be inserted:\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=cur;
	cur->link=next;
	
}

void insert_atend()
{	
	int pos,c;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter data\n ");
	scanf("%d",&(cur -> data));
	cur->link = NULL;
	tail -> link = cur;
	tail = cur;
	{
		next = head;
		while(c < pos)
		{
		prev = next;
		next = next -> link;
		c++;
		}
	}
}


void insert_before()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(cur->data));
	printf("Enter before which node we need to perform insertion:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
	{
		prev=next;
		next=next->link;
	}
	prev->link=cur;
	cur->link=next;
}

void insert_after()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(cur->data));
	printf("Enter after which node we need to perform insertion:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
		next=next->link;
	cur->link=next->link;
	next->link=cur;
}

void del_begin()
{
	cur = head;
	head=cur->link;
	cur->link = NULL;
	printf("deleted element is %d\n",cur->data);
	free(cur);
}


void del_end()
{
	cur = head;
	while(cur->link != tail)
		cur = cur->link;
	cur->link = NULL;
	next=tail;
	printf(" element to be deleted is %d",next->data);
	free(next);
	tail = cur;
}


void del_pos()
{
	int pos, c= 1;
	printf(" enter the position of deletion");
	scanf("%d",&pos);
	next = head;
	while(c<pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link=next->link;
	printf("deleted element is %d\n",next->data);
	next->link=NULL;
	free(next);
}

void del_before_node()
{	
	int value;
	printf("Enter data before deletion should be performed:\n");
	scanf("%d",&value);
	next=head;
	while(next->link->data!=value)
	{
		prev=next;
		next=next->link;
	}
	prev->link=next->link;
	next->link=NULL;
	printf("Deleted element is %d\n",next->data);
	free(next);
}

void del_after_node()
{
	int value;
	printf("Enter value after which deletion should be performed:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value)
	{
		prev=next;
		next=next->link;
	}
	prev=next->link;
	next->link=prev->link;
	printf("Deleted data is %d\n",prev->data);
	prev->link=NULL;
	free(prev);
	
}

void transversal()
{
	if(head==NULL)
	printf("list is empty \n");
	else
	{
		next = head;
		while(next != NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}

void sll_reverse()
{	int a[100];
	int i=0;
	cur=head;
	while(cur != NULL)
	{
		a[i++]=cur->data;
		cur=cur->link;
	
	}
	while(i>=0)
	{
		printf("%d->",a[i]);
		i--;
	}
}

void search()
{
	int value,flag=0,c=0;
	printf("Enter value to be searched\n:");
	scanf("%d",&value);
	next=head;
	while(next!=NULL)
	{
		if(next->data==value)
		{
			flag=1;
			break;
		}
		next=next->link;
		c++;
	}
	if(flag==1)
	{
		printf("Element present in the list at %d position\n",c);
	}
	else
		printf("Element not present in the list\n");
}

void sort()
{
	
	struct node *p1,*p2;
	p1=head;
	int c=0,i,t;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(i=0;i<c;i++)
	{	p2=head;
		while(p2->link!=NULL)
		{
			if(p2->data>p2->link->data)
			{
				t=p2->data;
				p2->data=p2->link->data;
				p2->link->data=t;
			}
			p2=p2->link;
		}
	}
	
	
}


int main()
{
	int ch;
	while(1)
	{
	printf(" program for single linked lists\n");
	printf(" 1-create\n 2-insert at begin\n 3- insert at position\n 4-insert at end\n 5-insert before");
	printf("\n 6-insert after node\n 7- delete at beginning\n 8-delete at end\n 9-delete at position\n 10-delete before node");
	printf("\n 11-delete after node\n 12-transversal\n 13-display in reverse\n 14-search\n 15-sort\n");
	printf("enter your choice \n");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1:create();
			break;
		case 2:insert_atbegin();
			break;
		case 3:insert_atpos();
			break;
		case 4:insert_atend();
			break;
		case 5:insert_before();
			break;
		case 6: insert_after();
			break;
		case 7:del_begin();
			break;
		case 8: del_end();
			break;
		case 9:del_pos();
			break;
		case 10: del_before_node();
			break;
		case 11: del_after_node();
			break;
		case 12:transversal();
			break;
		case 13:sll_reverse();
			break;
		case 14 : search();
			break;
		case 15 :sort();
			break;
		case 16: exit(0);
		}
	}
	return 0;
}
