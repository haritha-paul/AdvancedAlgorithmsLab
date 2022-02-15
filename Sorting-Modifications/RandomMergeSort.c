//Created by-Haritha Paul
#include<stdio.h>
#include<stdlib.h>
#define ARR_SIZE(arr) (sizeof((arr)) / sizeof((arr[0])))

/*User defined function to merge the elements into a single array from two sub-arrays*/
void merge(int array[],int p,int q,int r, int s)
{
  int temp[100];
  int i,j,k;
  i=p;
  j=r;
  k=0;
  while(i<=q && j<=s)
  {
    if(array[i]<array[j])
    {
      temp[k++]=array[i++];
    }
    else
    {
      temp[k++]=array[j++];
    }
  }
  while(i<=q)
  {
    temp[k++]=array[i++];
  }
  while(j<=s)
  {
    temp[k++]=array[j++];
  }
  for(int i=p,j=0;i<=s;i++,j++)
  {
    array[i]=temp[j];
  }

}
/*The given array is divided recursively, sorted and merged to provide the final array */

void mergesort(int num[], int low, int high,int size)
{

  if(low < high)
  {
    //Taking two random points instead of middle point
    int n1=(rand() % (high - low + 1)) + low;
    int n2 = (rand() % (high - low + 1)) + low;
    //merge sort first two subarrays
    mergesort(num,low,n1,size);
    mergesort(num,n1+1,n2-1,size);
    merge(num,low,n1,n1+1,n2);
    //merge sort resultant array with third subarray
    mergesort(num,n2+1,high,size);
    merge(num,low,n2,n2+1,high);
  }
}

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
  //performing Merge sort on the given array
  mergesort(arr,0,size-1,size);
  printf("Array after Merge Sort: ");
  printarray(arr,size);
  return 0;
}


