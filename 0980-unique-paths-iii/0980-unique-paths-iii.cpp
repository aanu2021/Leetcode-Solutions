class Solution {
public:
    
    int ans = 0;
    
    void dfs(vector<vector<int>>&grid,int i,int j,int curr){
        int m = grid.size();
        int n = grid[0].size();
        // Invalid Cells //
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1) return;
        // Goal State //
        if(grid[i][j]==2){
            if(curr==0){
                ans++;
            }
            return;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        curr--;
        // Explore all the 4-directional ways //
        dfs(grid,i+1,j,curr);
        dfs(grid,i-1,j,curr);
        dfs(grid,i,j+1,curr);
        dfs(grid,i,j-1,curr);
        grid[i][j] = temp;
        curr++;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int need = 0;
        int m = grid.size();
        int n = grid[0].size();
        int si = -1, sj = -1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 || grid[i][j]==0){
                    need++;
                }
                if(grid[i][j]==1){
                    si = i;
                    sj = j;
                }
            }
        }
        dfs(grid,si,sj,need);
        return ans;
    }
};