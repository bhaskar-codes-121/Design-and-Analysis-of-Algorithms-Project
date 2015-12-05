//---------------------------------------------------------------------------------------------------
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 3.1
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 29.07.2015
//---------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stddef.h>
int G[30][30];
int readGraph(FILE*fp)
{
    char*line = NULL;
    int size = 0,i=0,j=0;
    while(getline(&line,&size,fp)!=-1)
        {                                                                  //read a file from a line
            char *edge;int j=0;
            while((edge=strsep(&line,"\t"))!=NULL) G[i][j++] = atoi(edge);   //read an edge
            i++;
        }
}
int readfilemain()
{
    int i, j,rows;
    FILE *file;
    if((file = fopen("adjgraph.txt", "r"))==NULL)
    {
    printf("file not found!! \n");
    exit(1);
    }
    file = fopen("adjgraph.txt", "r");
    readGraph(file);
    printf("enter the no of rows/columns");
    scanf("%d",&rows);
        for(i=0;i<rows;i++)
        {
            for(j=0;j<rows;j++)
                {
                printf("%d \t",G[i][j]);
                }
        printf("\n");
        }
return 0;
}
