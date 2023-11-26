class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            int bitCnt = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j] == 1){
                    bitCnt++;
                }
                else{
                    bitCnt = 0;
                }
                dp[i][j] = bitCnt;
            }
        }
        
        for(int i=0;i<m;i++){
            sort(dp[i].begin(),dp[i].end());
        }
        
        int maxArea = 0;
        for(int i=0;i<m;i++){
            int currArea = 0;
            for(int j=0;j<n;j++){
                currArea = dp[i][j]*(n-j);
                maxArea = max(maxArea, currArea);
            }
        }
        
        return maxArea;
    }
};