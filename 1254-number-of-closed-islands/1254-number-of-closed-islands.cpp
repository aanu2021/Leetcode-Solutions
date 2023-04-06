class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j]==1){
            return;
        }
        grid[i][j] = 1;
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            dfs(grid,ni,nj,m,n);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                dfs(grid,i,0,m,n);
            }
            if(grid[i][n-1]==0){
                dfs(grid,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i]==0){
                dfs(grid,0,i,m,n);
            }
            if(grid[m-1][i]==0){
                dfs(grid,m-1,i,m,n);
            }
        }
        
        int comp = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    comp++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return comp;
    }
};