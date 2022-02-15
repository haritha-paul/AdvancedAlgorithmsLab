//Created by-Haritha Paul
#include <stdio.h>
//User defined function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
/*User defined function to partition the array with pivot as last element*/
int partition1(int array[], int l, int h)
{
  int pivot,i,j;
  pivot=array[h];
  i=l-1;
  for(j=l;j<h;j++)
  {
      if(array[j]<=pivot)
      {
          i++;
          swap(&array[i],&array[j]);
      }
   }
   swap(&array[i + 1], &array[h]);
   return (i + 1);
}
/*User defined function to partition the array with leftmost element as pivot*/
int partition2 (int A[],int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j =start + 1; j <= end ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[ j ] < piv)
          {
              swap (&A[i],&A[j]);
              i += 1;
          }
   }
   swap (&A[start] ,&A[i-1]) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

//The given array is partitioned and sorted recursively using divide and conquer approach
void quicksort(int num[],int low, int high)
{
  int array_size=high-1;
  if(low<high)
  {
    int p2=partition2(num,low,high); //with leftmost point as pivot
    int p1=partition1(num,low,high); //with rightmost point as pivot
    //The partitioned three subarrays is sorted recursively
    quicksort(num, low, p1-1);
    quicksort(num, p1+1,p2-1);
    quicksort(num,p2+1,high);
  }

}
/*User defined function to print the current status of the array*/
void printarray(int num[],int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d ",num[i]);
  }
}

int main(void)
{
  int arr[100];
  int size;
  //To get the array from the user
  printf("Enter the number of total elements: ");
  scanf("%d",&size);
  printf("Enter the elements of the array: ");
  for(int i=0; i<size; i++)
  {
    scanf("%d",&arr[i]);
  }
  //performing Quick sort on the given array
  quicksort(arr,0,size-1);
  printf("Array after Quick Sort: ");
  printarray(arr,size);
  return 0;
}
