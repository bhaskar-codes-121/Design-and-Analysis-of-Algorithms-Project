//---------------------------------------------------------------------------------------------------
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 3.4
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 13.08.2015
//----------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stddef.h>

void DFS(int);
int G[30][30],visited[4],n;
int readGraph(FILE*fp)
{
    char*line = NULL;
    int size = 0,i=0,j=0;
    while(getline(&line,&size,fp)!=-1)
        {                                                             					  //read a file from a line
            char *edge;int j=0;
            while((edge=strsep(&line,"\t"))!=NULL) G[i][j++] = atoi(edge);	   //read an edge
            i++;
        }
}
void DFS(int i)
{
    int j;
    printf("v%d\t",i+1);
    visited[i]=1;

       for(j=0;j<n;j++)
       {
                if(!visited[j]&&G[i][j]!=0&&G[i][j]!=9999)
            DFS(j);
       }
}
int dfsmain()
{
    int i,j;
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    FILE *file;
    if((file = fopen("adjgraph.txt", "r"))==NULL)
    {
    printf("file not found!! \n");
    exit(1);
    }
    file = fopen("adjgraph.txt", "r");
    readGraph(file);

     for(i=0;i<n;i++)
         {
           for(j=0;j<n;j++)
               {
               printf("%d",G[i][j]);
               }
       printf("\n");
       }
    for(i=0;i<n;i++)
        visited[i]=0;                   						//visited is initialized to zero
        printf("DFS :\n”);
  DFS(0);
return 0;
}

