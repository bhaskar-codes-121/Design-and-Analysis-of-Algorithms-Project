/* write a program to accept an array, sort it using either quicksort or mergesort. Then accept a number from the user and display whether the element exists in the list. If yes display the corresponding index number as well.
*/
#include<stdio.h>
#include<conio.h>
int binarySearch(int arr[],int first,int last,int search)
{
    if(first>last)                  return 9999;
    else
    {

    int mid = (first+last)/2;

    if(search==arr[mid])                { printf("first occurance found at index no %d",mid);return 0;}

    else if(search<arr[mid])         binarySearch(arr,first,mid-1,search);

    else                            binarySearch(arr,mid+1,last,search);
}
}


int binmain()
{
    printf("\nenter the array size \n");
    int size;
    scanf("%d",&size);
    int arr[size],i,res=0;
    printf("enter the array elements \n");

    for(i=0;i<size;i++)
    {
            scanf("%d",&arr[i]);
    }
    printf("\nThe array before sorting \n");

    for(i=0;i<size;i++)
    {
            printf("%d  ",arr[i]);
    }

    quickSort(arr,0,size-1);

    printf("\nThe array after sorting \n");

    for(i=0;i<size;i++)
    {
            printf("%d  ",arr[i]);
    }

    int search;
    printf("\nenter the element to search \n");
    scanf("%d",&search);

    res= binarySearch(arr,0,size-1,search);

     if(res==9999)printf("Not found\n");

     getch();
     return 0;

}

