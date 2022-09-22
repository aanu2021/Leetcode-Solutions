class Solution {
public:
    
    int dp[202][202];
    
    int func(vector<vector<int>>&grid,int i,int j,int m,int n,int prev){
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev){
            
            return 0;
            
        }
        
        if(dp[i][j]!=-1){
            
            return dp[i][j];
            
        }
        
        int op1=func(grid,i+1,j,m,n,grid[i][j]);
        int op2=func(grid,i-1,j,m,n,grid[i][j]);
        int op3=func(grid,i,j+1,m,n,grid[i][j]);
        int op4=func(grid,i,j-1,m,n,grid[i][j]);
        
        int currLen = 1 + max({op1,op2,op3,op4});
        
        return dp[i][j] = currLen;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int maxLen=0;
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(dp[i][j]==-1){
                    
                    int currLen=func(grid,i,j,m,n,-1);
                    
                   // cout<<currLen<<"\n";
                    
                    maxLen=max(maxLen,currLen);
                    
                   // maxLen=max(maxLen,func(grid,i,j,m,n,-1));
                    
                }
                
            }
            
        }
        
        return maxLen;
        
    }
};