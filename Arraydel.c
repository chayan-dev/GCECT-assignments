#include<stdio.h>
#include<stdlib.h>
void delete(int arr[],int idx,int *leng)
{
    int x=0;
    if(idx>=0 && idx<*leng-1)
    {
        x=arr->a[idx];
        for(int i=idx;i<arr->leng-1;i++)
        {
            arr->a[i]=arr->a[i+1];
            arr->leng--;
        }
    }
    else if(idx==arr->leng-1)
    {
        arr->leng--;
    }
}
int main(void)
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int leng=sizeof(n)/sizeof(int);
    int idx;
    printf("Enter the index where the element shall be deleted:=");
    scanf("%d",&idx);
    delete(&arr,idx);
    for(int i=0;i<=leng-1;i++)
    {
        printf("%d ",arr[i]);
    }
}