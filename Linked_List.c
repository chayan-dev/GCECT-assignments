#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void create(struct Node *first,struct Node *last,int arr[],int n);
void display(struct Node *first);
int main(void)
{
    struct Node *first=NULL,*last=NULL;
    int arr[]={10,20,30,40,50};
    int n=5;
    create(first,last,arr,n);
    display(first);
}
void create(struct Node *first,struct Node *last,int arr[],int n)
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
void display(struct Node *first)
{
    struct Node *h=first;
    if(h==NULL)
    {
        printf("h is null\n");
    }
    else
        while(h!=NULL)
        {
            printf("%d ",h->data);
            h=h->next;
        }
}