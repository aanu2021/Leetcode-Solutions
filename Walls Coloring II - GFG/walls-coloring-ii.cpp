//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &grid) {
        int n = grid.size();
        int k = grid[0].size();
        if(n==0) return 0;
        if(k==0){
            return -1;
        }
        if(k==1){
            if(n>1) return -1;
        }
        vector<vector<int>>dp(n,vector<int>(k,1e9));
        for(int i=0;i<k;i++){
            dp[0][i] = grid[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>prefix(k,1e9);
            vector<int>suffix(k,1e9);
            for(int j=0;j<k;j++){
                prefix[j] = dp[i-1][j];
                suffix[j] = dp[i-1][j];
            }
            for(int j=1;j<k;j++){
                prefix[j] = min(prefix[j],prefix[j-1]);
            }
            for(int j=k-2;j>=0;j--){
                suffix[j] = min(suffix[j],suffix[j+1]);
            }
            for(int j=0;j<k;j++){
                int left = (j-1 >= 0 ? prefix[j-1] : 1e9);
                int right = (j+1 < k ? suffix[j+1] : 1e9);
                dp[i][j] = min(left,right) + grid[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends