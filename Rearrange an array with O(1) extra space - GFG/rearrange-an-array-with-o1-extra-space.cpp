//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        
        for(int i=0;i<n;i++){
            arr[i] += (arr[arr[i]]%n)*n;
        }
        
        for(int i=0;i<n;i++){
            arr[i] /= n;
        }
        
    }
};

// a -> b
// newVal = a + (b*n)
// newVal /= n = (a + (b*n))/n
// newVal = (a/n) + b = 0 + b = b
// oldVal = a
// newVal = b



//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends