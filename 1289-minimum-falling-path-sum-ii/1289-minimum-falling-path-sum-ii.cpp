class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0;i<n;i++){
            dp[0][i] = grid[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int>prefix(n);
            vector<int>suffix(n);
            for(int j=0;j<n;j++){
                prefix[j] = dp[i-1][j];
                suffix[j] = dp[i-1][j];
            }
            for(int j=1;j<n;j++){
                prefix[j] = min(prefix[j], prefix[j-1]);
            }
            for(int j=n-2;j>=0;j--){
                suffix[j] = min(suffix[j], suffix[j+1]);
            }
            for(int j=0;j<n;j++){
                int currMin = INT_MAX;
                if(j > 0) currMin = min(currMin, prefix[j-1]);
                if(j+1 < n) currMin = min(currMin, suffix[j+1]);
                dp[i][j] = currMin + grid[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};