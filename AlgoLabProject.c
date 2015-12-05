//---------------------------------------------------------------------------------------------------
//
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Author(s) : Bhaskar Tejaswi
//
//---------------------------------------------------------------------------------------------------
#include<stdio.h>
#include "Quicksort.c"
#include "BinarySearch.c"
#include "MergeSort.c"
#include "MatrixMultiplication.c"
#include "ReadFile.c"
#include "ReadEdges.c"
#include "BFS.c"
#include "DFS.c"
#include "heapsort.c"
#include "priority.c"
#include "setunionfind.c"
#include "jobscheduling.c"
int main(){
printf("Name : Bhaskar Tejaswi\n");
printf("Subject : Design And Analysis of Algorithms\n");
printf("Sem : 5th\n");
int choice=0;
while(choice!=13){
printf("\nEnter your choice\n");
printf("1. Binary Search\n");
printf("2. Quick Sort\n");
printf("3. Merge Sort \n");
printf("4. Matrix Chain Multiplication\n");
printf("5. Read Graph from File\n");
printf("6. Read Edges from Adjacency Matrix of a Graph\n");
printf("7. Perform DFS\n");
printf("8. Perform BFS\n");
printf("9. Heap Sort\n");
printf("10.Priority Queue\n");
printf("11.Set Union, Find \n");
printf("12.Job Scheduling\n");
printf("13.Exit\n");
scanf("%d",&choice);
switch(choice){
    case 1: binmain();
            break;
    case 2: quickmain();
            break;
    case 3: mergemain();
            break;
    case 4: matrixmain();
            break;
    case 5: readfilemain();
            break;
    case 6: readedgesmain();
            break;
    case 7: bfsmain();
            break;
    case 8: dfsmain();
            break;
    case 9: heapsortmain();
            break;
    case 10:prioritymain();
            break;
    case 11:setunionfindmain();
            break;
    case 12:jobmain();
            break;
    default:
            printf("Thank You!");
}
}
return 0;
}
