class Solution {
public:
    
    int currarea=0;
    
    void dfs(vector<vector<int>>&grid,int i,int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        
        currarea++;
        
        grid[i][j]=0;
        
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int maxarea=0;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    
                    currarea=0;
                    
                    dfs(grid,i,j);
                    
                    maxarea=max(maxarea,currarea);
                    
                }
                
            }
            
        }
        
        return maxarea;
        
    }
};