//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Check for the presence of 1.
        bool found = false;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                found = true;
                break;
            }
        }
        
        if(!found) return 1;
        
        for(int i=0;i<n;i++){
            if(arr[i] <= 0 || arr[i] > n){
                arr[i] = 1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1] > 0){
                arr[abs(arr[i])-1] *= -1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                return i+1;
            }
        }
        
        return n+1;
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends