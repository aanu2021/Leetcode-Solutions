class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        dp[m-1][n-1] = min(grid[m-1][n-1], 0);
        for(int i=n-2;i>=0;i--){
            dp[m-1][i] = min(0, grid[m-1][i] + dp[m-1][i+1]);
        }
        for(int i=m-2;i>=0;i--){
            dp[i][n-1] = min(0, grid[i][n-1] + dp[i+1][n-1]);
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = min(0, max(dp[i+1][j], dp[i][j+1]) + grid[i][j]);
            }
        }
        return abs(dp[0][0]) + 1;
    }
};