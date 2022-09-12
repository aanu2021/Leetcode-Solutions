class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int i,int j,int curr,int col){
        
        int m=grid.size();
        int n=grid[0].size();
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=curr){
            
            return;
            
        }
        
        grid[i][j]=col;
        
        dfs(grid,i-1,j,curr,col);
        dfs(grid,i+1,j,curr,col);
        dfs(grid,i,j-1,curr,col);
        dfs(grid,i,j+1,curr,col);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        
        if(grid[sr][sc]==color){
            
            return grid;
            
        }
        
        dfs(grid,sr,sc,grid[sr][sc],color);
        
        return grid;
        
    }
};