//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int W) 
	{ 
	   // vector<vector<int>>dp(n+1,vector<int>(W+1,1e9));
	    vector<int>dp(W+1,1e9);
	    dp[0] = 0;
	    for(int i=0;i<n;i++){
	        for(int j=coins[i];j<=W;j++){
	            dp[j] = min(dp[j], dp[j-coins[i]] + 1);
	        }
	    }
	    return dp[W] >= 1e9 ? -1 : dp[W];
	   // dp[0][0] = 0;
	   // for(int i=1;i<=n;i++){
	   //     dp[i][0] = 0;
	   // }
	   // for(int i=1;i<=n;i++){
	   //     for(int j=1;j<=W;j++){
	   //         dp[i][j] = dp[i-1][j];
	   //         if(j >= coins[i-1]){
	   //             dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i][j]);
	   //         }
	   //     }
	   // }
	   // return dp[n][W] >= 1e9 ? -1 : dp[n][W];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends