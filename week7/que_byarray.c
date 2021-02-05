#include <stdio.h>
#include <Stdlib.h>
#define maxsize 5
int f=-1,r=-1,i,queue[maxsize];
int isfull(){
	if(r==maxsize-1)
	return -1;
	else
	return 0;
}
int isempty(){
	if(f==-1)
	return 1;
	else
	return 0;
}
void enqueue(int data){
	if(f==-1)
		f=0;
	queue[++r]=data;
}
int dequeue(){
	int x = queue[f];
	if(f==r)
	f=r=-1;
	else
	f++;
	return x;
}
void display(){
	for(i=f;i<=r;i++)
	printf("%d\t",queue[i]);
}

int main(){
	int ch,x;
	while(1){
	printf("\nPROGRAMS FOR QUEUE");
	printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: if(isfull())
		printf("queue overflow\n");
		else{
		printf("enter data to insert:");
		scanf("%d",&x);
		enqueue(x);
		}
		break;
	case 2: if(isempty())
		printf("queue underflow\n");
		else if(f!=r)
		printf("deleted element %d \n",dequeue());
		else{
		printf("deleted element %d \n",dequeue());
		if(f==r)
		f=r=-1;
		}
		break;
	case 3: display();
		break;
	case 4: exit(0);
		}
	}
}