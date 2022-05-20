class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        for(int i=m-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                
                if(i==m-1 && j==n-1){
                    dp[i][j]=min(0,grid[i][j]);
                }
                
                else if(i==m-1){
                    dp[i][j]=min(0,dp[i][j+1]+grid[i][j]);
                }
                
                else if(j==n-1){
                    dp[i][j]=min(0,dp[i+1][j]+grid[i][j]);
                }
                
                else{
                    dp[i][j]=min(0,max(dp[i+1][j]+grid[i][j],dp[i][j+1]+grid[i][j]));
                }
                
            }
            
        }
        
        return abs(dp[0][0])+1;
        
    }
};