#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st)
{
    printf("Enter the size of the stack:");
    int n;
    scanf("%d",&n);
    st->size=n;
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}
void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x=st->s[st->top--];
    }
    return x;
}
void display(struct Stack *st)
{
    for(int i=st->top;i>=0;i--)
    {
        printf("%d ",st->s[i]);
    }
    printf("\n");
}
int main(void)
{
    struct Stack st;
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(&st);
    for(int i=0;i<n;i++)
    {
        push(&st,arr[i]); //storing the array in the stack
    }
    printf("Elements of stack after using the push function to store each value of the array into the stack is:->\n");
    display(&st); //displaying stack
    printf("result after using the pop function\n");
    printf("%d\n",pop(&st)); //pop the first element of the stack
    printf("The final stack after using the pop function is:\n");
    display(&st);// display after poping the element 
}