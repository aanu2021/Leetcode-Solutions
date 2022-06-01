class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        int land=0,water=0;
        
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    dp[i][j]=0;
                    land++;
                }
                
                else{
                    water++;
                }
                
            }
        }
        
        if(land==0 || water==0){
            return -1;
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    continue;
                }
                
                for(int k=0;k<4;k++){
                    
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<n && y>=0 && y<n){
                        dp[i][j]=min(dp[i][j],dp[x][y]+1);
                    }
                    
                }
                
            }
        }
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                if(grid[i][j]==1){
                    continue;
                }
                
                for(int k=0;k<4;k++){
                    
                    int x=i+dx[k];
                    int y=j+dy[k];
                    
                    if(x>=0 && x<n && y>=0 && y<n){
                        dp[i][j]=min(dp[i][j],dp[x][y]+1);
                    }
                    
                }
                
            }
        }
        
        
        int ans=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        
        
        return ans;
        
    }
};