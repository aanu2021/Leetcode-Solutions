class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int func(vector<vector<int>>&grid, int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxLen = 1;
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                if(grid[ni][nj] > grid[i][j]){
                    maxLen = max(maxLen, 1 + func(grid, ni, nj, m, n, dp));
                }
            }
        }
        return dp[i][j] = maxLen;
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int maxLen = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == -1){
                    maxLen = max(maxLen, func(grid, i, j, m, n, dp));
                }
            }
        }
        return maxLen;
    }
};