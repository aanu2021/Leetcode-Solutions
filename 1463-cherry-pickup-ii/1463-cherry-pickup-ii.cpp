class Solution {
public:
    
    int dp[71][71][71];
    
    int func(vector<vector<int>>&grid,int r,int c1,int c2){
        
        if(r>=grid.size() || c1<0 || c2<0 || c1>=grid[0].size() || c2>=grid[0].size()){
            return -1e9;
        }
        
        if(r==grid.size()-1){
            
            if(c1==c2){
                return grid[r][c1];
            }else{
                return grid[r][c1]+grid[r][c2];
            }
            
        }
        
        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }
        
        int cherry=0;
        
        if(c1==c2){
            cherry+=grid[r][c1];
        }
        
        else{
            cherry+=grid[r][c1];
            cherry+=grid[r][c2];
        }
        
        int p1=func(grid,r+1,c1-1,c2-1);
        int p2=func(grid,r+1,c1-1,c2);
        int p3=func(grid,r+1,c1-1,c2+1);
        
        int p4=func(grid,r+1,c1,c2-1);
        int p5=func(grid,r+1,c1,c2);
        int p6=func(grid,r+1,c1,c2+1);
        
        int p7=func(grid,r+1,c1+1,c2-1);
        int p8=func(grid,r+1,c1+1,c2);
        int p9=func(grid,r+1,c1+1,c2+1);
        
        int ans1=max(max(p1,p2),max(p3,p4));
        int ans2=max(max(p5,p6),max(p7,p8));
        ans2=max(ans2,p9);
        
        ans1=max(ans1,ans2);
        
        cherry+=ans1;
        
        return dp[r][c1][c2]=cherry;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(grid,0,0,n-1);
        
        return ans;
        
    }
};