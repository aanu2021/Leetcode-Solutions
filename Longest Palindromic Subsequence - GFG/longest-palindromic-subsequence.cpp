//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        
        int n = s.length();
        
        int dp[n+1][n+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = 2;
            }
            else{
                dp[i][i+1] = 1;
            }
        }
        
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i+L-1;
                if(s[i]==s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        
        return dp[0][n-1];
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends