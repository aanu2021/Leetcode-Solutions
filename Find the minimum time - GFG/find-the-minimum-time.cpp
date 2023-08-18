//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int S1, int S2, int N){
         int low = 1, high = 1e9;
         int ans = -1;
         while(low <= high){
             int mid = (low + high)/2;
             int sum = (mid/S2) + (mid/S1);
             if(sum >= N){
                 ans = mid;
                 high = mid - 1;
             }
             else{
                 low = mid + 1;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends