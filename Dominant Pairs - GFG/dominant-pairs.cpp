//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        
        int bar = (n/2);
        int m = (n/2);
        
        sort(arr.begin(),arr.begin()+bar);
        sort(arr.begin()+bar,arr.end());
        reverse(arr.begin(),arr.begin()+bar);
        reverse(arr.begin()+bar,arr.end());
        
        int ans = 0;
        
        int j = n - 1;
        
        for(int i=bar-1;i>=0;i--){
            while(j >= bar && arr[i] >= 5*arr[j]){
                j--;
            }
            ans += (n-1-j);
        }
        
        return ans;
        
    }  
};

// 0 0    0 0
// 0 1    2 3


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends