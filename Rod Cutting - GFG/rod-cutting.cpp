// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        
         vector<int>cost(n+1);
         
         for(int i=1;i<=n;i++){
             cost[i]=price[i-1];
         }
        
         vector<int>dp(n+1,0);
         
         dp[1]=cost[1];
         
         for(int i=2;i<=n;i++){
             
             dp[i]=cost[i];
             
             for(int j=1;j<i;++j){
                 
                 dp[i]=max(dp[i],cost[j]+dp[i-j]);
                 
             }
             
         }
         
         return dp[n];
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends