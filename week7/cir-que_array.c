#include<stdio.h>
#include<stdlib.h>
# define maxsize 5
int cqueue[maxsize];
int f = -1, r = -1;
int isfull()
{
	if(f==(r+1)%maxsize)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(f==-1)
	return -1;
	else
	return 0;
}

void enqueue(int data)
{
    	if(f ==(r+1)%maxsize)
        	printf("Circular Queue Overflow\n");
    	else if(f == -1){
		f=r= 0;
		cqueue[r]=data;
	}
    	else{
		r= (r+1)%maxsize;
		cqueue[r]=data;
	}
}
void dequeue()
{
	if(f == -1)
	{
        	printf("Circular Queue Underflow\n");
    	}
	else if(f==r)
	{
		printf("deleted element is : %d\n",cqueue[f]);
		f=r=-1;
	}
    	else
    	{
        	printf("deleted element is : %d\n",cqueue[f]);
		f=(f+1)%maxsize;
    	}
}

void display()
{
	int i=f;
	if(isempty())
		printf("Circular queue is empty");
	else
	{
		while(i!=r)
		{
			printf("%d\t",cqueue[i]);
			i=(i+1)%maxsize;
		}
		printf("%d\t",cqueue[i]);
	}
}
int main()
{
    int ch,x;
    while(1)
	{
	printf("\nPROGRAM FOR CIRCULAR QUEUE\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
    switch(ch)
        {
		case 1 :if(isfull())
			printf("circular queue is overflow");
		    	else
			{
				printf("Enter data for insertion : ");
                    		scanf("%d", &x);
                    		enqueue(x);
			}
                    	break;
		case 2 :if(isempty())
			printf("circular queue is undeflow");
		    	else
			{
                    		dequeue(x);
			}
                    	break;
            	case 3 :display();
                    	break;
            	case 4 :exit(0);
        }
	}
}