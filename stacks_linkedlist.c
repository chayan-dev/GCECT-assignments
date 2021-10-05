#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int top;
    struct Node *next;
}*first=NULL,*last=NULL;
void push(int n);
void display();
int pop();
int main(void)
{
    int n;
    printf("Enter the size of the Linked List:-");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        push(t);
    }
    display();
    printf("result after popping->%d\n",pop());
    printf("stack after popping->\n");
    display();
}
void push(int n)
{
    if(first==NULL)
    {
        first=(struct Node *)malloc(sizeof(struct Node));
        last=first;
        first->data=n;
        first->next=NULL;
        
    }
    else
    {
        struct Node *temp;
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=n;
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
void display()
{
    struct Node *h=first;
    if(h==NULL)
    {
        printf("h is null\n");
    }
    else
    {
        while(h!=NULL)
        {
            printf("%d ",h->data);
            h=h->next;
        }
        printf("\n");
    }
}
int pop()
{
    struct Node *t;
    int x=-1;
    if(first==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        t=first;
        first=first->next;
        x=t->data;
        free(t);
    }
    return x;
}