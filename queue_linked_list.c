#include<stdlib.h>
#include<stdio.h>
struct Node 
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void enqueue(int x);
int dequeue();
void display();
int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display(first);
    printf("Result after dequeing->%d\n",dequeue());
    display(first);
}
void enqueue(int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data=x;
        t->next=NULL;
        if(first==NULL)
        {
            first=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}
int dequeue()
{
    int x=-1;
    struct Node *t ;
    if(first==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x=first->data;
        t=first;
        first=first->next;
        free(t);
    }
    return x;
}
void display()
{
    struct Node *p=first;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}