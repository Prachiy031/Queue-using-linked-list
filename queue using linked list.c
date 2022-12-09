#include<stdio.h>
#include<stdlib.h>

struct abc
{
  int data;
  struct abc *next;
};
struct abc *front = NULL,*rear = NULL;
void enqueue(),dequeue(),display();
int main()
{
    int ch,y;
    do
    {
    printf("Enter choice:\n");
    printf("1.enqueue 2.dequeue 3.display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        enqueue();
        break;
        
        case 2:
        dequeue();
        break;
        
        case 3:
        display();
        break;
        
    }
    printf("Do you want to continue?\n");
    scanf("%d",&y);
    
    }
    while(y==1);
    return 0;
}
void enqueue()
{
    struct abc *new;
    new =(struct abc *)malloc(sizeof(struct abc));
    if(new==NULL)
    {
        printf("Overflow\n");        //if queue is full(cp doesen't provide any memory if queue is full)
    }
    else
    {
        if(rear==NULL)               //if only one element is there
        {
            printf("Enter data:\n"); 
            scanf("%d",&new->data);
            new->next = NULL;
            rear = new;
            front = new;
        }
        else 
        {
            printf("Enter data:\n");   //if some elements are there
            scanf("%d",&new->data);
            new->next = NULL;
            rear->next = new;
            rear=new;
        }
    }
    
}
void dequeue()
{
    struct abc *temp;
    temp = front;
    if(rear==front==-1)           //if empty queue
    {
        printf("Underflow\n");
    }
    else
    {
        if(front==rear)          //if single element is there
        {
            printf("Deleted data is:%d",front->data);
            front=NULL;
            rear = NULL;
            free(temp);
        }
        else
        {
            printf("Deleted data is:%d",front->data); //if some elements are there
            front=front->next;
            free(temp);
        }
    }
}

void display()
{
    struct abc *temp ;
    temp= front;
    if(temp==NULL)
    {
        printf("oops queue is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
        printf("%d ",temp->data);
        temp = temp->next;
        }
    }
}