#include<stdio.h>
#include<malloc.h>
int main()
{   int option;
    int pos,i=1;
    struct node
    {


    int data;
    struct node *next;
     };

    struct node *new_node,*current,*start=NULL,*prev,*next_node;
    int n;
    printf("Enter the number of nodes needed : ");
    scanf("%d",&n);
    printf("Enter the values in order :\n");
    for(int i=0;i<n;i++)
    {
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=NULL;
     if(start==NULL)
     {
         start=new_node;
         current=new_node;
     }
     else{
        current->next=new_node;
        current=new_node;
     }
    }
    printf("Linked list is :\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf(" %d ->",current->data);
    }


    printf("NULL\n");
    int aa=1;
    while(aa==1)
    {

    printf("Select Option:\n");
    printf("1.Insert at beginning\n");
    printf("2.Insert at end\n");
    printf("3.Insert at any position\n");

    printf("4.Delete from begining\n");
    printf("5.Delete from end\n");
    printf("6.Delete from any position\n");
    printf("7.Exit\n");
    printf("What do you want to perform ? : ");

    scanf("%d",&option);



    switch(option)
    {

case 1:
    {

    printf("\nEnter the value of node to insert at begining : ");
    new_node=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;

    }
    else{
       new_node->next=start;
       start=new_node;
    }
     printf("Linked list after insertion is :\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf(" %d ->",current->data);
    }
     printf("NULL");
     break;
    }
case 2:
    {



     printf("\nEnter the value of node to insert at end : ");
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=NULL;
     current=start;
     while(current->next!=NULL)
     {
         current=current->next;
     }
     current->next=new_node;
     printf("Linked list after insertion at end is :\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf(" %d ->",current->data);
    }
     printf("NULL\n");
     break;
    }
case 3:
    {


     int count=0;
      for(current=start;current!=NULL;current=current->next)
    {
        count++;
    }

     printf("Enter the position to insert : ");
     scanf("%d",&pos);
     if (pos>count)
     {

         printf("Invalid position\n");
     }
     else{

        current=start;
        while(i<pos-1)
        {
            current=current->next;
            i++;
        }
     printf("Enter data : ");
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=current->next;
     current->next=new_node;

     }
      printf("Linked list after insertion  is :\n");
      for(current=start;current!=NULL;current=current->next)
    {
        printf(" %d ->",current->data);
    }
     printf("NULL\n");
     break;
    }
case 4:
    {
        current =start;
        start=start->next;
        free(current);
        printf("Linked list after deletion :\n");
        for(current=start;current!=NULL;current=current->next)
        {
        printf(" %d ->",current->data);
        }
       printf("NULL\n");
      break;

    }
case 5:
    {
        current=start;
        while(current->next !=0)
        {
            prev=current;
            current=current->next;
        }
        if(current==NULL)
        {
          free(current);
        }
        else{
            prev->next=NULL;

        }
        free(current);
         printf("Linked list after deletion :\n");
        for(current=start;current!=NULL;current=current->next)
        {
        printf(" %d ->",current->data);
        }
       printf("NULL\n");
      break;

    }
case 6:
    {
       int i=1;
       current=start;
       printf("Enter position to delete : ");
       scanf("%d",&pos);
       while(i<pos-1)
       {
           current=current->next;
           i++;
       }
       next_node=current->next;
       current->next=next_node->next;
       free(next_node);
        printf("Linked list after deletion is : ");
        for(current=start;current!=NULL;current=current->next)
        {
        printf(" %d ->",current->data);
        }
       printf("NULL\n");
      break;
    }
case 7:
    {

        printf("Exited\n");
       aa=0;
       break;



    }
default:
    {
        printf("select valid option\n");

    }
    }
    }
}
