#include<stdio.h>
typedef struct
{
    int mat[2][2];
}Matrix;
void mul(Matrix a,Matrix b);
void add(Matrix a,Matrix b);
int main(void)
{
    char operation;
    printf("Enter any algebraic expression b/w + or * :\n");
    scanf("%c",&operation);
    Matrix a,b;
    printf("For the first matrix enter the data\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&a.mat[i][j]);
        }
    }
     printf("For the second matrix enter the data\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&b.mat[i][j]);
        }
    }
    if(operation=='+')
    {
        add(a,b);
    }
    else if(operation=='*')
    {
        mul(a,b);
    }
    else 
    {
        printf("Invalid algebraic expression try again");
    }
    return 0;
}
void mul(Matrix a,Matrix b)
{
    Matrix c;
    for(int row=0;row<2;row++)
    {
        for(int col=0;col<2;col++)
        {
            int here=0;
            for(int i=0;i<2;i++)
            {
                here+=a.mat[row][i]*b.mat[i][col];
            }
            c.mat[row][col]=here;
        }
    }
    printf("The result of multiplication of both matrices is:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",c.mat[i][j]);
        }
        printf("\n");
    }
}
void add(Matrix a,Matrix b)
{
    Matrix c;
    for (int i = 0; i <2; ++i)
    {
        for (int j = 0; j <2; ++j) 
        {
            c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
        }
    }
    printf("The result of addition of both matrices is:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",c.mat[i][j]);
        }
        printf("\n");
    }
}