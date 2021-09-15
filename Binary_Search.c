#include<stdio.h>
int linear(int arr[],int n,int target);
int binary(int arr[],int n,int target);
int main(void)
{
    int n;
    printf("Searching through Linear search\n");
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the values of array\n");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number you want to find:");
    int target;
    scanf("%d",&target);
    if(linear(arr,n,target)!=-1)
    {
        printf("The index of %d is %d\n",target,linear(arr,n,target));
    }
    else
    {
        printf("%d does not exist in the given array",target);
    }
    printf("\n");
    printf("Searching through binary search\n");
    int p;
    printf("Enter the array length:");
    scanf("%d",&p);
    int arr1[p];
    printf("Enter a sorted array:\n");
    for(int i=0;i<p;i++)
    {
        scanf("%d",&arr1[i]);
    }
    int target1;
    printf("Enter the number you want to find:");
    scanf("%d",&target1);
    if(binary(arr1,p,target1)!=-1)
    {
        printf("The index of %d is %d\n",target1,binary(arr1,p,target1));
    }
    else
    {
        printf("%d does not exist in the given array",target1);
    }
}
int linear(int arr[],int n,int target)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
        else
        {
            continue;
        }
    }
    return -1;
}
int binary(int arr[],int n,int target)
{
    int low=0,end=n-1,ans=-1;
    while(low<=end)
    {
        int mid=low+(end-low)/2;
        if(target==arr[mid])
        {
            ans=mid;
            return ans;
        }
        else if(target>arr[mid])
        {
            low=mid+1;
        }
        else //if(target<arr[mid])
        {
            end=mid-1;
        }

    }
    return ans;
}