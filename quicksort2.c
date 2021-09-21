#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size)
{
  int i;
  for(i=0; i<size; i++)
     printf("%d ", arr[i]);
     
  printf("\n");   
}


void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp= *yp;
  *yp=temp;
}

int partition(int arr[], int left, int right)
{
  int i = left+ rand()%(right-left+1);  // random number in the range left- right::: pivot
  
  //we move pivot to the beginning of our array:
  
  swap(&arr[i],&arr[left]);
  int pivot = left;
  //left is one index after pivot:
  
  left++;

 // how long should i update the right nd left and keep walking?
 
 while(left<=right)
 
 {
 
   //left will work:
   while(left <= right && arr[left]<= arr[pivot]) 
   
   
      left++; 
      
      //after left stops , we go to right
   while(left <= right && arr[right]> arr[ pivot])  
        right --;  
        
   //now we must swap right and left. however it is not always the case.
   //if the loop breaks for the reason left>right:
   //we need to swap right with the pivot
   
   if(left< right)
     swap(&arr[left], &arr[right]);
    // end of while and we do the process until they cross each other      
 
 }
 swap(&arr[right], &arr[pivot]);
 
 return right;
}


void quicksort(int arr[], int low, int high)

{
  if (low<high)
  {
    int k= partition(arr, low,high);
    quicksort(arr, low, k-1);
    quicksort(arr,k+1, high);
  
  }
}

int main()
{
  int arr[100], arrCopy[100];
  int size, i;
  printf("How many numbers to sort?\n");
  scanf("%d", &size);
  
  
  
  
  for(i=0; i<size; i++)
  {
  
  printf("Enter number %d:" , i+1);
  scanf("%d", &arr[i]);
  arrCopy[i]=arr[i];
  
  }
  
   printf("\narray before sorting:\n");
   printArray(arr,size);
   printf("\n");
   quicksort(arrCopy,0, size-1);
   printf("\nSorted array using Quick sort:\n");
   printArray(arrCopy,size);
   return 0;
  
  

}