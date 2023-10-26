//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = (s[i] != s[i+1]);
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i + L - 1;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends