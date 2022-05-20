class Solution {
public:
    
    int dp[51][51][51][51];
    
    int func(vector<vector<int>>&grid,int r1,int c1,int r2,int c2,int n){
        
        if(r1<0 || c1<0 || r1>=n || c1>=n || r2<0 || c2<0 || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return -1e9;
        }
        
        if(r1==n-1 && c1==n-1){
            
            return grid[r1][c1];
            
        }
        
        if(dp[r1][c1][r2][c2]!=-1){
            return dp[r1][c1][r2][c2];
        }
        
        
        int cherry=0;
        
        if(r1==r2 && c1==c2){
            cherry+=grid[r1][c1];
        }
        
        else{
            cherry+=grid[r1][c1];
            cherry+=grid[r2][c2];
        }
        
        int a=func(grid,r1+1,c1,r2+1,c2,n);
        int b=func(grid,r1+1,c1,r2,c2+1,n);
        int c=func(grid,r1,c1+1,r2+1,c2,n);
        int d=func(grid,r1,c1+1,r2,c2+1,n);
        
        cherry+=max(max(a,b),max(c,d));
        
        return dp[r1][c1][r2][c2]=cherry;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(grid,0,0,0,0,n);
        
        return (ans<=0 ? 0 : ans);
        
    }
};