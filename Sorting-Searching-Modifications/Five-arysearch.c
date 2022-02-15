//Created by Haritha Paul
#include<stdio.h>

int Five_ary_search(int arr[], int low, int high, int k)
{
    if(low <= high)
    {
       //Dividing the array into five partitions
       int m1=low+(high-low)/5;
       int m2=m1+(high-low)/5;
       int m3=m2+(high-low)/5;
       int m4=m3+(high-low)/5;
       if(arr[m1]==k)
       {
         return m1;
       }
       if(arr[m2]==k)
       {
           return m2;
       }
       if(arr[m3]==k)
       {
           return m3;
       }
       if(arr[m4]==k)
       {
           return m4;
       }
       //to check whether the key is in first partition
       if(k < arr[m1])
       {
         high=m1-1;
         return Five_ary_search(arr,low,high,k);
       }
       //to check whether the key is in second partition
       if(k > arr[m1] && k < arr[m2])
       {
           low=m1+1;
           high=m2-1;
           return Five_ary_search(arr,low,high,k);
       }
       //to check whether the key is in third partition
       if(k > arr[m2] && k < arr[m3])
       {
          low=m2+1;
          high=m3-1;
          return Five_ary_search(arr,low,high,k);
       }
       //to check whether the key is in fourth partition
       if(k > arr[m3] && k < arr[m4])
       {
           low=m3+1;
           high=m4-1;
           return Five_ary_search(arr,low,high,k);
       }
       //to check whether the key is in fifth partition
       if(k > arr[m4])
       {
           low=m4+1;
           return Five_ary_search(arr,low,high,k);
       }

    }

    return -1;

}


//User defined function for swapping two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//User-defined function to sort using selection-sort
void sort(int num[], int n)
{
    int min,i,j;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(num[j]<num[min])
            {
                min=j;
            }
        }
        swap(&num[min],&num[i]);
    }

}

int main(void)
{
    int a[100];
    int size, key,val;
    //To get the array from the user
    printf("Enter the number of total elements: ");
    scanf("%d",&size);
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    //Sorting the input array to perform binary search
    sort(a,size);
    val=Five_ary_search(a,0,size-1,key);
    if(val==-1)
    {
      printf("Element not found in array!");
    }
    else
    {
      printf("Element found at position %d !",val);
    }
    return 0;
}
