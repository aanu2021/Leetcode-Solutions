//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
    
        void reverseArr(int arr[],int l,int r){
            if(l > r) return;
            while(l < r){
                swap(arr[l++],arr[r--]);
            }
        }
    
        void merge(int arr[],int low,int mid,int high){
            int i=low, j=mid+1;
            while(i<=mid && arr[i] < 0){
                i++;
            }
            while(j<=high && arr[j] < 0){
                j++;
            }
            reverseArr(arr,i,mid);
            reverseArr(arr,mid+1,j-1);
            reverseArr(arr,i,j-1);
        }
    
        void mergesort(int arr[],int low,int high){
            if(low < high){
                int mid = (low + high)/2;
                mergesort(arr,low,mid);
                mergesort(arr,mid+1,high);
                merge(arr,low,mid,high);
            }
        }
    
        void Rearrange(int arr[], int n)
        {
             mergesort(arr,0,n-1);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends