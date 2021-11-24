#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;

}*head=NULL,*last=NULL;
void display();
void create(int d);
void insert(int pos,int d);
int len();
int main(void)
{
    int n;
    printf("Enter the number of data you want to insert:");
    scanf("%d",&n);
    while(n--)
    {
        int t;
        printf("Enter the data:");
        scanf("%d",&t);
        create(t);
    }
    display();
    int pos,data;
    printf("Enter the pos where you want to insert:");
    scanf("%d",&pos);
    printf("Enter the data which you want to insert:");
    scanf("%d",&data);
    insert(pos,data);
    display();
}
void insert(int pos,int d)
{
    if(pos<0 || pos>len())
    {
        printf("Position is out of bounds\n");
        return;
    }
    struct Node *temp;
    if(pos==0)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=d;
        if(head==NULL)
        {
            head=temp;
            head->next=head;
            head=temp;
        }
        else
        {
            last->next=temp;
            temp->next=head;
            head=temp;
        }
    }
    else
    {
        struct Node *p=head;
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=d;
        temp->next=p->next;
        p->next=temp;
    }
}
void display()
{
    struct Node *h=head;
    do
    {
        printf("%d ",h->data);
        h=h->next;
    } while (h!=head);
    printf("\n");
}
void create(int d)
{
    struct Node *temp;
    if(head==NULL)
    {
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=d;
        head->next=head;
        last=head;
    }
    else
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=d;
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
    
}

int len()
{
    struct Node *h=head;
    int c=0;
    do
    {
        c++;
        h=h->next;
    } while (h!=head);
    return c;
}
