//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high) return;
        int partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        do{
          
           while(i <= high && arr[i] <= pivot){
               i++;
           }
           while(j > low && arr[j] > pivot){
               j--;
           }
           
           if(i < j){
               swap(arr[i],arr[j]);
           }
               
        }while(i < j);
        swap(arr[low],arr[j]);
        return j;
    }
};

// 4 1 3 9 7
//     j i

// 1 1 2 10 4 6 3 9 7
//     j i         


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends