//---------------------------------------------------------------------------------------------------
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 3.2
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 13.08.2015
//---------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stddef.h>
int G[30][30];
typedef struct Edge {
int u;                // represents the first end-vertex of the edge
int cost;             // represents the cost/weight of the edge
int v;                // represents the second end-vertex of the edge
} edge ;

int getEdges(edge edges[]){

           int k = 0; // number of edges in the graph
           int i,j;
           for(i = 0; i<= 4- 1; i++)
           {
                   for (j = 0; j<=4 - 1;j++)
                   {
                       if (G[i][j] != 0 && G[i][j] !=9999)
                            {

                               if (j > i || G[i][j] != G[j][i])
                                                   {
                               edge e;
                               e.u = i;
                               e.v = j;
                               e.cost = G[i][j];
                               edges[k++] = e;
                               }
                           }
                   }
           }
           return k;
}
int readGraph(FILE*fp)
{
    char*line = NULL;
    int size = 0,i=0,j=0;
    while(getline(&line,&size,fp)!=-1)
       {                                                                                                         //read a file from a line
           char *edge;int j=0;
           while((edge=strsep(&line,"\t"))!=NULL) G[i][j++] = atoi(edge);   //read an edge
           i++;
       }
}
int readedgesmain() {
int i, j,rows;
edge edges[900];
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
               printf("%d",G[i][j]);
               }
       printf("\n");
       }

int numEdges=getEdges(edges);
printf("the no of edges is %d\n",numEdges);
printf(" start\tend\tcost\t\n");
       for(i=0;i<numEdges;i++)
       {
         printf("%d\t%d\t%d\t",edges[i].u+1,edges[i].v+1,edges[i].cost);
         printf("\n");
       }
return 0;
}

