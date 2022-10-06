class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int i,int j,int prev,vector<vector<bool>>&visited){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] < prev || visited[i][j]){
            
            return;
            
        }
        
        visited[i][j] = true;
        
        dfs(grid,i-1,j,grid[i][j],visited);
        dfs(grid,i+1,j,grid[i][j],visited);
        dfs(grid,i,j-1,grid[i][j],visited);
        dfs(grid,i,j+1,grid[i][j],visited);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>vis1(m,vector<bool>(n,false));
        vector<vector<bool>>vis2(m,vector<bool>(n,false));
        
        // Water flow from the pacific ocean //
        
        for(int i=0;i<n;i++){
            
            dfs(grid,0,i,-1,vis1);
            
        }
        
        for(int i=1;i<m;i++){
            
            dfs(grid,i,0,-1,vis1);
            
        }
        
        // Water flow from the atlantic ocean //
        
        for(int i=0;i<n;i++){
            
            dfs(grid,m-1,i,-1,vis2);
            
        }
        
        for(int i=0;i<m-1;i++){
            
            dfs(grid,i,n-1,-1,vis2);
            
        }
        
        vector<vector<int>>ans;
        
        int cnt = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis1[i][j] && vis2[i][j]){
                    cnt++;
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
    }
};