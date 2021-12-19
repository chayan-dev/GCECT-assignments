#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}*first=NULL,*last=NULL;
void create(int val);
int len(struct Node *p);
void insert(int val,int pos);
void display();
int main(void)
{
    int p;
    do
    {
        printf("Enter 1 to create a doubly Linked list of user defined size (The size of Linked List can be increases or decreased later):\n");
        printf("Enter 2 to insert any value at a user defined valid position in the doubly Linked list:\n");
        printf("Enter 3 to display the values in the doubly Linked list:\n");
        scanf("%d",&p);
        if(p==1)
        {
            int n;
            printf("How many elements you want to insert:");
            scanf("%d",&n);
            while (n--)
            {
                int t;
                printf("Enter the digit you want to insert:");
                scanf("%d",&t);
                create(t);
            }
        }
        if (p==2)
        {
            int val,pos;
            printf("Enter the value which you want to insert in the Doubly Linked List:");
            scanf("%d",&val);
            printf("Enter the position where you want to insert the value:");
            scanf("%d",&pos);
            insert(val,pos);
        }
        if(p==3)
        {
            display();
            printf("\n");
            
        }
    } while (p!=-1);
}
void create(int val)
{
    struct Node *t;
    if(first==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=val;
        t->next=NULL;
        t->prev=NULL;
        first=t;
        last=first;
        return;
    }
    else
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=val;
        t->prev=last;
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

int len(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

void insert(int val,int pos)
{
    struct Node *t;
    struct Node *q;
    if(pos<0||pos>len(first))
    {
        return ;
    }
    if(pos==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=val;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        q=first;
        for(int i=0;i<pos-1;i++)
        {
            q=q->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=val;
        t->prev=q;
        t->next=q->next;
        if(q->next)
        {
            q->next->prev=t;
        }
        q->next=t;
    }
}

void display()
{
    struct Node *p=first;
    if(first==NULL)
    {
        printf("Linked List is NULL");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}