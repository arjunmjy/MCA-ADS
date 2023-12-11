#include<stdio.h>

void main()
{
int n;
printf("Enter the size of queue : ");
scanf("%d",&n);
int queue[n];
int front=-1;
int rear=-1;
void enqueue()
{
    if((rear+1)%n!=front){
    int data;
    printf("\nEnter the data : ");
    scanf("%d",&data);
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=data;

    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=data;
    }
    }
    else if((rear+1)%n==front){
	printf("\nQueue is full\n");
    }
}

void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty\n");

    }
    else if(front==rear)
    {
        printf("\n%d is dequeued\n",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d is dequeued\n",queue[front]);
        front=(front+1)%n;

    }
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty!!\n");

    }
    else if(front==rear){
	printf("\nCircular Queue :\n%d\n",queue[i]);
	}
    else
    {
	printf("\nCircular Queue : \n");
        while(i!=rear)
        {
            printf("%d <- ",queue[i]);
            i=(i+1)%n;
        }
        printf("%d\n",queue[rear]);
    }
}
void search()
{
	int val,i=front,flag=0;
	printf("\nEnter the element to be searched : ");
	scanf("%d",&val);
	while(i!=rear){
		if(queue[i]==val){
			flag=1;
			break;
		}
		i=(i+1)%n;
	}
	if(queue[rear]==val)
	flag=1;
	if(flag==1)
	printf("\nElement found in the queue.\n");
	else
	printf("\nElement not found in the queue.\n");
}

    int opt;
    int a=1;
    while(a==1)
    {
    printf("\n");
    printf("1.ENQUEE\n");
    printf("2.DEQUEE\n");
    printf("3.SEARCH\n");
    printf("4.DISPLAY\n");
    printf("5.EXIT\n");
    printf("\nENTER YOR CHOICE : ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        {
            enqueue();
            break;
        }
    case 2:
        {
            dequeue();
            break;
        }
    case 3:
        {
            search();
            break;
        }
    case 4:
        {
            display();
            break;
        }
    case 5:
        {
            a=0;
            printf("\nEXITED\n");
            break;
        }
    default:
        {
            printf("\nENTER A VALID CHOICE\n");
        }

    }
   }
}
