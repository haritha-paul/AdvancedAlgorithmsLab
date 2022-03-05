//Created by Haritha Paul
#include<stdio.h>
#include<limits.h>

int m[20][20];
int o[20][20];
int d[20];

//User defined function to print the optimal sequence of matrix multiplication
void print_order_miltiply(int i, int j)
{
    if(i==j)
    {
        printf("A%d",i);
    }
    else
    {
        printf("(");
        print_order_miltiply(i, o[i][j]);
        print_order_miltiply(o[i][j]+1,j);
        printf(")");

    }
}
//User defined to initialize matrix to an upper triangular matrix with diagonal elements zero.
void init(int N)
{
    for(int i=0;i<N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            m[i][i]=0;
            m[i][j]=INT_MAX;
            o[i][j]=0;
        }
    }
}
//Calculates the number of scalar multiplications between each pair of matrices
void matrix_chain_multiply_modern(int N)
{
    long int cost;
    for(int i=N; i>=0; i--)
    {
        for(int j=i; j<=N; j++)
        {
            if(i==j)
            {
                m[i][j]=0;
            }
            else
            {
                for(int k=i; k<j;k++)
                {
                    //recursive equation
                    cost=m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j]+d[i-1]*d[j]*(d[k]-1);
                    if(cost < m[i][j])
                    {
                        m[i][j]=cost;
                        o[i][j]=k;
                    }
                }
            }
        }
    }
}
//Calculates the minimum of the scalar multiplications in the cost matrix
int min_multiplications(int D[], int i, int j)
{
    int min_count=INT_MAX;
    int min;
    if(i==j)
    {
        return 0;
    }
    for(int k=i;k<j;k++)
    {
        min=min_multiplications(D,i,k)+min_multiplications(D, k+1,j)+D[i-1]*D[k]*D[j]+D[i-1]*D[j]*(D[k]-1);
        if(min < min_count)
        {
            min_count=min;
        }
    }
    return min_count;
}
//Driver code
int main(void)
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    printf("Enter the dimensions of the matrices: \n");
    for(int i=0; i<=n;i++)
    {
        printf("D%d: ",i);
        scanf("%d",&d[i]);
    }
    init(n);
    matrix_chain_multiply_modern(n);
    printf("\nCost Matrix:  \n\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            printf("m[%d][%d]:%d ",i,j,m[i][j]);
        }
        printf("\n");
    }
    printf("\nMinimum number of scalar multiplications: %d\n\n", min_multiplications(d,1,n));
    printf("Sequence of Matrix Multiplication: \n");
    print_order_miltiply(1,n);
    system("pause");
    return 0;
}
