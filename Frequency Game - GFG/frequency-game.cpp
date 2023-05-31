//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
       unordered_map<int,int>freq;
       for(int i=0;i<n;i++) freq[arr[i]]++;
       
       int minOcc = n+1;
       int maxEle = -1;
       
       for(auto &itr : freq){
           minOcc = min(minOcc,itr.second);
       }
       for(auto &itr : freq){
           if(itr.second == minOcc){
               maxEle = max(maxEle,itr.first);
           }
       }
       
       return maxEle;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends