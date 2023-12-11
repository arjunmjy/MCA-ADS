#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL,*new_node,*current,*tail;
void insert_beginning()
{
 new_node=(struct node *)malloc(sizeof(struct node));
 printf("Enter data : ");
 scanf("%d",&new_node->data);
 new_node->prev=NULL;
 new_node->next=NULL;
 if(start==NULL)
 {
     start=new_node;

 }
 else{
    start->prev=new_node;
    new_node->next=start;
    start=new_node;
 }
}
void insert_end()
{
  new_node=(struct node *)malloc(sizeof(struct node));
 printf("Enter data : ");
 scanf("%d",&new_node->data);
 new_node->prev=NULL;
 new_node->next=NULL;
 if(start==NULL)
 {
     start=new_node;

 }
 else
 {
   tail->next=new_node;
   new_node->prev=tail;
   tail=new_node;
 }
}
int count()
{     int count=0;
      for(current=start;current!=NULL;current=current->next)
    {
        count++;
    }
    return count;
}
void insert_at_position()
{
  int i=1;
  int pos;
  int co=count();
  printf("Enter position to insert : ");
  scanf("%d",&pos);
  if(pos<1)
  {
      printf("Invalid location!!\n");
  }
  else if(pos>co)
  {
      printf("Please check the size of list\n");
  }
  else if(pos==1)
  {
      insert_beginning();
  }
  else if(pos==co)
  {
      insert_end();
  }
  else
  {
     new_node=(struct node *)malloc(sizeof(struct node));
     printf("Enter data : ");
     scanf("%d",&new_node->data);
     new_node->prev=NULL;
     new_node->next=NULL;
     current=start;
    while(i<pos-1)
    {
     current=current->next;
     i++;
    }
    new_node->prev=current;
    new_node->next=current->next;
    current->next=new_node;
    new_node->next->prev=new_node;
  }
}
void search()
{
 int val;
 int flag=0;
 printf("Enter value to be searched : ");
 scanf("%d",&val);
 int i=1;
 current=start;
 while(current!=NULL)
 {
    if(current->data==val)
    {
        flag=1;
        break;
    }
    current=current->next;
    i++;
 }
 if(flag==1)
 {
     printf("Value is found at %d\n\n",i);
 }
 else{
    printf("Value is not found!!");
 }
}
void delete_beg()
{

   current=start;
   if(start==NULL)
   {
       printf("List is empty!!\n");
   }
   else
    {
     start=start->next;
     start->prev=NULL;
     free(current);
   }
}
void delete_end()
{
if(start==NULL)
   {
       printf("List is empty!!\n");
   }
   else
    {
    current=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(current);
   }
}
void delete_pos()
{
    int j=1;
    int pos;
    int co;
    printf("Enter the position to delete:\n");
    scanf("%d",&pos);
    co=count();
    if(start==NULL)
    {
        printf("There is nothing to delete\n");
    }
    else if(pos==1)
    {
        delete_beg();
    }
     else if(pos>co)
    {
        printf("Invalid location!!\n");
    }
    else if(pos==co)
    {
        delete_end();
    }
    else{
    current=start;
    while(j<pos)
    {
     current=current->next;
     j++;
    }
   current->prev->next=current->next;
   current->next->prev=current->prev;
   free(current);
    }
}

void display()
{
    printf("Doubly linked list is : \n");
    current =start;

   while(current != NULL) {
      printf("[%d]<->",current->data);
      current = current->next;
   }
   printf("NULL\n\n");

}
int main()
{
    int opt;
    int a=1;
    while(a==1)
    {

    printf("\n");
    printf("1.INSERT AT BEGINNING\n");
    printf("2.INSERT AT END\n");
    printf("3.INSERT AT ANY POSITION\n");
    printf("4.DELETE FROM BEGINNING\n");
    printf("5.DELETE FROM END\n");
    printf("6.DELETE FROM ANY POSITION\n");
    printf("7.SEARCH\n");
    printf("8.DISPLAY LIST\n");
    printf("9.EXIT\n");
    printf("SELECT AN OPTION:");
    scanf("%d",&opt);
    printf("\n");
    switch(opt)
    {

    case 1:
        {
            insert_beginning();
            display();
            break;
        }
    case 2:
        {
            insert_end();
            display();
            break;
        }
    case 3:
        {
            insert_at_position();
            display();
            break;
        }
    case 4:
        {
            delete_beg();
            display();
            break;
        }
    case 5:
        {
            delete_end();
            display();
            break;
        }
    case 6:
        {
            delete_pos();
            display();
            break;
        }
    case 7:
        {
            search();
            break;
        }
    case 8:
	{
	    display();
	    break;
	}
    case 9:
        {
            printf("EXITED\n");
            a=0;
            break;
        }
    default:
        {
            printf("enter valid option");
        }
    }
}
}
