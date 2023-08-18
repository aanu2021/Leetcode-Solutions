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
    void merge(int arr[], int l, int m, int r)
    {
        int len = r-l+1;
        int temp[len];
        int idx = 0;
        int i = l, j = m+1;
        while(i<=m && j<=r){
            if(arr[i] <= arr[j]){
                temp[idx++] = arr[i++];
            }
            else{
                temp[idx++] = arr[j++];
            }
        }
        while(i<=m){
            temp[idx++] = arr[i++];
        }
        while(j<=r){
            temp[idx++] = arr[j++];
        }
        idx = 0;
        for(int i=l;i<=r;++i){
            arr[i] = temp[idx++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r){
            int m = (l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends