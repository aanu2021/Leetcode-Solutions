class Solution {
public:
    
    int dp[205][205];
    
    int func(int i,int j,int m,int n,vector<vector<int>>&grid,int prev){
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int curr1=1+func(i+1,j,m,n,grid,grid[i][j]);
        int curr2=1+func(i-1,j,m,n,grid,grid[i][j]);
        int curr3=1+func(i,j+1,m,n,grid,grid[i][j]);
        int curr4=1+func(i,j-1,m,n,grid,grid[i][j]);
        
        return dp[i][j]=max(max(curr1,curr2),max(curr3,curr4));
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                ans=max(ans,func(i,j,m,n,grid,grid[i][j]-1));
                
            }
            
        }
        
        return ans;
        
    }
};