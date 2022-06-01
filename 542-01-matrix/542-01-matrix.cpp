class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dp[i][j]=0;
                }
            }
        }
        
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==0){
                    continue;
                }
                
                for(int k=0;k<4;k++){
                    
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<m && y>=0 && y<n){
                        
                        dp[i][j]=min(dp[i][j],dp[x][y]+1);
                        
                    }
                    
                }
                
            }
        }
        
        
        for(int i=m-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                
                if(grid[i][j]==0){
                    continue;
                }
                
                for(int k=0;k<4;k++){
                    
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<m && y>=0 && y<n){
                        
                        dp[i][j]=min(dp[i][j],dp[x][y]+1);
                        
                    }
                    
                }
                
            }
            
        }
        
        return dp;
        
    }
};