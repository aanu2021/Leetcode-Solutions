// { Driver Code Starts
// Heap Sort in C
#include <stdio.h>
  
// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
 // } Driver Code Ends
//User function Template for C


void heapify(int arr[], int n, int i) {
   
   int largest=i;
   
   int l=(2*i+1);
   int r=(2*i+2);
   
   if(l<n && arr[largest]<arr[l]){
       largest=l;
   }
   
   if(r<n && arr[largest]<arr[r]){
       largest=r;
   }
   
   if(largest!=i){
       
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        
        heapify(arr,n,largest);
       
   }
    
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
  
   for(int i=n-1;i>=0;i--){
       
       heapify(arr,n,i);
       
   }
   
   
   for(int i=n-1;i>0;i--){
       
       int temp=arr[0];
       arr[0]=arr[i];
       arr[i]=temp;
       
       heapify(arr,i,0);
       
   }
  
}

// { Driver Code Starts.
  
// Driver code
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr, n);
    printArray(arr, n);
    }
  }  // } Driver Code Ends