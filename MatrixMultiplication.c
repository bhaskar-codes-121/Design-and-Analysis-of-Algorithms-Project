//---------------------------------------------------------------------------------------------------
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 2
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 22.07.2015
//---------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>

int mcm(int n,int p[],int s[][n+1])
{
    int i=0,l=2,k=0,q,j=0;
    int m[n+1][n+1];
    for(i=1;i<=n;i++)
    {
        m[i][i] = 0;
        if(i!=n)
            {
                m[i][i+1] = p[i-1]*p[i]*p[i+1];
            }
    }

    for(l=2;l<=n-1;l++)
    {
        for(i=1;i<=n-l;i++)
        {
            j = i+l;
            m[i][j]=999999;
            for(k=i;k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
            }
        }
    }
    int ans = m[1][n];
    return ans;
}

int mcorder(int size,int s[][size],int i,int j)
{
    if(i==j)
        printf("   A[%d]   ",i);
    else if(j == i +1)
            printf("<A[%d].A[%d]>",i,j);
    else
    {

        printf("(");
        mcorder(size,s,i,s[i][j]);
        mcorder(size,s,s[i][j] + 1,j);
        printf(")");
    }
}

int matrixmain()
{
    int i;
    printf("enter the number of matrices you wish to multiply : \n");
    int size;
    scanf("%d",&size);
    int m[size+1][size+1],p[size+1];
    printf("enter the rows and columns in continuation : \n");
    for(i=0;i<=size;i++)
    {
        scanf("%d",&p[i]);
    }

    int s[size][size];
    int result = mcm(size,p,s);
    printf("the minimum no of scalar multiplications needed is %d \n" , result);
    mcorder(size,s,1,size);
    return 0;
}


