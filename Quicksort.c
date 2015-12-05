#include<stdio.h>
#include<conio.h>
int partition(int arr[],int start, int end)
{

    int pivot  = arr[end],i;                                    //set pivot to the last element of the array
    int partitionIndex = start;

    for(i = start;i<=end-1;i++)                                  //traverse the array from start to end-1
    {
          if(arr[i]<=pivot)
          {
                int temp = arr[i];                               //swap ith element with the element at partitionIndex
                arr[i] = arr[partitionIndex];
                arr[partitionIndex]=temp;
                partitionIndex++;                               //increment the value of part

          }
    }
    int t = arr[partitionIndex];                                 //swap last element with the element at partitionIndex
    arr[partitionIndex] = arr[end];
    arr[end] = t;
    return partitionIndex;                                       //return partitionIndex

}

int quickSort(int arr[],int first, int last)
{   int pivotIndex,i;
    if(first<last)                                              //this is to check whether there are more than one elements in the array under consideration
                {
                    pivotIndex = partition(arr,first,last);     //partition the array
                    quickSort(arr,first,pivotIndex-1);          //recursively call quicksort from first to pivotIndex-1 and from pivotIndex+1 to last
                    quickSort(arr,pivotIndex+1,last);
                }
}

int quickmain()
{
    printf("enter the size of the array \n");                   //enter the array
    int size;
    scanf("%d",&size);
    int arr[size],i=0;
    for(i=0;i<size;i++)
    {
         scanf("%d",&arr[i]);
    }

    quickSort(arr,0,size-1);                                    //call quickSort()


    printf("The sorted array :\n");
    for(i=0;i<size;i++)
    {
         printf("%d\n",arr[i]);                                 //display the sorted array
    }
    getch();
    return 0;
}

