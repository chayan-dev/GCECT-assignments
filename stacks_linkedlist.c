#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
}*top=NULL;
void push(int x);
int pop();
int peek(int pos);
void display();
int main(void)
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    printf("Result after popping is -> %d\n",pop());
    display(top);

}
void push(int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
       printf("Stack is Full\n");
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop()
{
    int x=-1;
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    int x=-1;
    struct Node *p=top;
    for(int i=0;p!=NULL && i<pos-1;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        x=p->data;
        return x;
    }
    return x;
}
void display()
{
    struct Node *p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}