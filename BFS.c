//---------------------------------------------------------------------------------------------------
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 3.3
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 12.08.2015
//----------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stddef.h>
int G[30][30],visited[30],n;
int queue[30];
void BFS(int v)
{
    int front=0;
    int    rear=-1;
    int w;
        for(w=0;w<n;w++){
            if(!visited[w]&&G[v][w]!=0&&G[v][w]!=9999)
            {
            queue[++rear]=w;
            }
    }
    if(front<=rear){
    visited[queue[front]] = 1;
    BFS(queue[front++]);
    }
}
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
int bfsmain()
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
    BFS(0);
    printf("BFS : \n");
    for(i=0;i<n;i++){
        if(visited[i])
           printf("%d\t",i);
          else
           printf("\n Bfs is not possible");
    }
 return 0;
}