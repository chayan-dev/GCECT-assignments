#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *p;
};
void create(struct Queue *q,int size)
{
    q->p=(int *)malloc(size*sizeof(int));
    q->front=-1;
    q->rear=-1;
}
void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->p[q->rear]=x;    
    }
}
int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x=q->p[q->front];
    }
    return x;
}
void display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.p[i]);
        
    }
    printf("\n");
}
int main(void)
{
    struct Queue q;
    int size;
    printf("Enter the size of the Queue:-");
    scanf("%d",&size);
    create(&q,size);
    for(int i=0;i<size;i++) 
    {
        printf("Enter the %d element:-",i);
        int temp;
        scanf("%d",&temp);
        enqueue(&q,temp);
    }
    printf("The Queue after implementing the enqueue function:->\n");
    display(q);
    printf("After calling the dequeue function:->\n");
    printf("Deleted value is-> %d\n",dequeue(&q));
    printf("the resultant Queue after deleting a value:-\n");
    display(q);


}
