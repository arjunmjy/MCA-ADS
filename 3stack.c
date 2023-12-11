#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *new_node,*current ,*top=NULL;

void push()
{
	new_node=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value to be pushed into the stack : ");
	scanf("%d",&new_node->data);
	new_node->next=top;
	top=new_node;
	printf("Stack is :\n");
	for(current=top;current!=NULL;current=current->next)
	{
		printf("[ %d ]\n",current->data);
	}

}

void pop()
{
	if(top!=NULL)
   {
	current=top;
	top=top->next;
	free(current);
	printf("Stack is :\n");
	for(current=top;current!=NULL;current=current->next)
		{
			printf("[ %d ]\n",current->data);
		}
    }
        else
    {
	printf("Stack is empty!!!\n");
    }
}
void search()
{
	int pos=0,key,flag=0;
	if(top==NULL)
	{
		printf("Stack is empty!!\n");
	}
	else{   
		printf("Enter the data to be searched: ");
        	scanf("%d",&key);
		for(current=top;current!=NULL;current=current->next)
		{
			pos++;
			if(current->data==key)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf("Element is found at Position %d \n",pos);
		}
		else
		{
			printf("Element not found!!\n");
		}
	}

}

int main()
{
	int opt,a=1;
	while(a)
	{
		printf("1.Push\n2.Pop\n3.Search\n4.Exit\n");
		printf("Enter the operation you want to perform : ");
		scanf("%d",&opt);

		switch(opt)
		{
		case 1: 
		{
    			push();
    			break;
    		}
		case 2: 
		{
    			pop();
    			break;
    		}
		case 3: 
		{
    			search();
    			break;
    		}
		case 4: 
		{
    			printf("Exited");
    			a=0;
    			break;
    		}
		default:
		{
    			printf("Invalid input!!!");
    		}
		}
	}
}


