#include<stdio.h>
#include<conio.h>
int merge(int a[],int low,int mid,int high)
{
                                                //there are two arrays in a[]  one from low to mid, and the other from mid+1 to high
    int h = low,i=low,j=mid+1,b[high-low+1],k;  //i  is being used to fill elements in auxillary array b[], h is being used for left array
    while((h<=mid) && (j<=high))                //j is being used to traverse right array
    {
                   if(a[h]<=a[j])
                   {
                                 b[i] = a[h];
                                 h=h+1;
                   }
                   else
                   {
                                   b[i] = a[j];
                                   j=j+1;
                   }

    i=i+1;                                        //one element put in array b[], increment the corresponding counter by one
    }                                             //while loop closes

    if(h>mid)                                    //the entire left array has been traversed ... copy right array as it is
    {
                for(k=j;k<=high;k++)
                {
                                    b[i] = a[k];
                                    i++;
                }
    }

    else

    {
                for(k=h;k<=mid;k++)             // there are some elements still left in the left array... copy them in b[]
                {
                                    b[i] = a[k];
                                    i++;

                }

    }                                           //so filling of b[] is done...

    for(k=low;k<=high;k++)                      //copy all elements of b[] back in a[]
       {
           a[k] = b[k];
       }
}
int mergeSort(int arr[],int low,int high)
{
    if(low<high)                                //there is more than one element in the array
    {
           int mid = (low+high)/2;
           mergeSort(arr,low,mid);              //recursively call mergeSort from low to mid
           mergeSort(arr,mid+1,high);           //recursively call mergeSort from mid+1 to high
           merge(arr,low,mid,high);             //merge the two arrays from low to mid and from mid+1 to high

     }
} //mergesort closes

int mergemain()
{
 printf("enter the size of the array \n");      //take array input from user
    int size;
    scanf("%d",&size);
    int arr[size],i=0;
    for(i=0;i<size;i++)
    {
         scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,size-1);                     //call mergeSort
    printf("The sorted array :\n");
    for(i=0;i<size;i++)
    {
         printf("%d\n",arr[i]);                  //display the sorted array
    }
    getch();
    return 0;
}


