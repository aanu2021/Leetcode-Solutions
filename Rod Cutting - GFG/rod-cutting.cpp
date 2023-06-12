//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        
        vector<int>dp(n+1,0);
        
        dp[0] = 0;
        
        for(int i=1;i<=n;i++){
            int currCost = price[i-1];
            for(int j=1;j<i;j++){
                currCost = max(currCost, price[j-1] + dp[i-j]);
            }
            dp[i] = currCost;
        }
        
        return dp[n];
        
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends