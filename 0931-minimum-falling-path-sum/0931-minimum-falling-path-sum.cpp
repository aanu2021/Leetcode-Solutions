class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++) dp[0][i] = grid[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = grid[i][j] + dp[i-1][j];
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + grid[i][j]);
                if(j+1 < n) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + grid[i][j]);
            }
        }
        int minSum = INT_MAX;
        for(int i=0;i<n;i++) minSum = min(minSum, dp[n-1][i]);
        return minSum;
    }
};