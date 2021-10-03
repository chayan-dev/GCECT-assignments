#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void create(int arr[],int n);
void display();
int count_nodes(struct Node *first);
void insert(int pos,int d);
int main(void)
{
    int n;
    printf("Enter the length of the Linked list you want to make:-");
    scanf("%d",&n);
    int arr[5];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    display();
    int d,pos;
    printf("Enter the number which you want to insert:-\n");
    scanf("%d",&d);
    printf("Enter the position in which you want to insert:-\n");
    scanf("%d",&pos);
    insert(pos,d);
    display();
}
void create(int arr[],int n)
{
    struct Node *temp;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
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
int count_nodes(struct Node *first)
{
    struct Node *h=first;
    int c=0;
    while(h!=NULL)
    {
        c++;
        h=h->next;
    }
    return c;
}
void insert(int pos,int d)
{
    if(pos<0||pos>count_nodes(first))
    {
        printf("Position is out of bounds\n");
        return;
    }
    else
    {
        struct Node *temp;
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=d;
        if(pos==0)
        {
            temp->next=first;
            first=temp;
        }
        else
        {
            struct Node *p=first;
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
    }
}