class Solution {
public:
    
    int dp[202][202];
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int func(vector<vector<int>>&grid,int i,int j,int m,int n,int prev){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] <= prev) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int currLen = 0;
        
        for(int dir = 0 ; dir < 4 ; dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            currLen = max(currLen,func(grid,ni,nj,m,n,grid[i][j]));
        }
        
        return dp[i][j] = 1 + currLen;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int maxLen = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] == -1){
                    maxLen = max(maxLen,func(grid,i,j,m,n,-1));
                }
            }
        }
        return maxLen;
    }
};