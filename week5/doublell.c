#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node * prev;
	struct node *next;
};
struct node *head = NULL, *tail= NULL, *cur, *t1, *t2;
void create()
{
	int n;
	printf(" enter number of nodes :  \n");
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
	{	
		cur = (struct node*)malloc(sizeof(struct node));
		printf("enter current node data \n");
		scanf("%f",&(cur->data));
		cur->prev = NULL;
		cur->next=NULL;
		if(head==NULL)
		{
			head = tail = cur;
		}
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
}



void insert_atbegin()
{
	cur =(struct node*)malloc(sizeof(struct node));
	printf("enter  data:\n");
	scanf("%f",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev=cur;
	head = cur;
}

void insert_pos()
{
	int c=1,pos;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&cur->data);
	printf("enter position:\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos && t1 != NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next = cur;
	cur->prev = t2;
	cur->next = t1;
	t1->prev = cur;
}

void insert_atend()
{
	cur =(struct node*)malloc(sizeof(struct node));
	printf("enter current node data:\n");
	scanf("%f",&(cur->data));
	cur->next = NULL;
	cur->prev = tail;
	tail->next = cur;
	tail=cur;
}

void insert_before()
{
	float value;
	cur =(struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur->data));
	printf(" enter the data of before which we need to perform");
	scanf("%f",&value);
	t1=head;
	while(t1!= NULL && t1->data != value)
	{
		t2 =t1;
		t1 = t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}

void insert_after()
{
	float value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter current node data\n");
	scanf("%f",&(cur->data));
	printf(" enter the value to be inserted after node:\n");
	scanf("%f",&value);
	t1 = head;
	while(t1 -> data != value && t1 != NULL)
	{
		t1 = t1->next;
	}
	cur->next=t1->next;
	t1->next->prev= cur;
	t1->next=cur;
	cur->prev=t1;
}

 void del_atbegin()
{
	cur = head;
	head=head->next;
	head-> prev = NULL;
	cur->next = NULL;
	printf("deleted element %f",cur->data);
	free(cur);
}

void del_atend()
{
	cur = tail;
	tail = tail->prev;
	tail->next = NULL;
	cur->prev = NULL;
	printf("deleted element %f",cur->data);
	free(cur);
}

void del_pos()
{
	int pos,c=1;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");	
	scanf("%d",&pos);
	t1 = head;
	while(c < pos && t1!=NULL)
	{
		t2 =  t1;
		t1=t1->next;
		c++;
	}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("deleted data is %f",t1->data);
	free(t1);
}
	
void del_before()
{
	float value;
	printf("Enter value before we need to delete:\n");
	scanf("%f",&value);
	t1=head;
	while(t1->next->data!=value && t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("Deleted element is %f\n",t1->data);
	free(t1);
	
}


void del_after()
{	float value;
	printf(" enter the data of a node for deletion");
	scanf("%f",&value);
	t1 = head;
	while(t1->data!= value && t1 != NULL)
	{
		t1 = t1 ->next;
	}
	t2 = t1->next;
	t1 -> next = t2 -> next;
	t2-> next->prev=t1;
	printf(" deleted element %f", t2->data);
	free(t2);
}

void display_forward()
{
	if(head == NULL)
	printf(" double linked list is empty");
	else
	{
		cur = head;
		printf(" element od DLL are\n");
		while( cur != NULL)
		{
			printf("%f<->", cur->data);
			cur= cur=cur->next;
		}
	}
}


void display_reverse()
{
	if(head == NULL)
	printf(" double linked list is empty");
	else
	{
		cur = tail;
		while( cur != NULL)
		{
			printf("%f<->", cur->data);
			cur= cur=cur->prev;
		}
	}
}

void search()
{
	float value,flag=0;
	int c=1;
	printf("Enter value to be searched\n:");
	scanf("%f",&value);
	t1=head;
	while(t1!=NULL)
	{
		if(t1->data==value)
		{
			flag=1;
			break;
		}
		t1=t1->next;
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
		p1=p1->next;
	}
	for(i=0;i<c;i++)
	{	p2=head;
		while(p2->next!=NULL)
		{
			if(p2->data>p2->next->data)
			{
				t=p2->data;
				p2->data=p2->next->data;
				p2->next->data=t;
			}
			p2=p2->next;
		}
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf(" program for double linked lists\n");
		printf(" 1-create\n 2-insert at begin\n 3- insert at position\n 4-insert at end\n 5-insert before");
		printf("\n 6-insert after node\n 7- delete at beginning\n 8-delete at end\n 9-delete at position\n 10-delete before node");
		printf("\n 11-delete after node\n 12-display forward\n 13-display reverse\n 14-search\n 15-sort\n");
		printf("enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{

		case 1: create();
			break;
		case 2: insert_atbegin();
			break;
		case 3: insert_pos();
			break;
		case 4: insert_atend();
			break;
		case 5: insert_before();
			break;
		case 6: insert_after();
			break;
		case 7: del_atbegin();
			break;
		case 8 : del_atend();
			break;
		case 9 : del_pos();
			break;
		case 10 : del_before();
			break;
		case 11: del_after();
			break;
		case 12 : display_forward();
			break;
		case 13 : display_reverse();
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
