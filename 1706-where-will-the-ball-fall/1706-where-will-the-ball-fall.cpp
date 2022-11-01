class Solution {
public:
    
   int dfs(vector<vector<int>>&grid,int i,int j){
       
       if(j<0 || j>=grid[0].size()) return -1;
       
       if(i==grid.size()) return j;
       
       if(j+1<grid[0].size() && grid[i][j]==1 && grid[i][j+1]==-1){
           return -1;
       }
       
       if(j-1>=0 && grid[i][j]==-1 && grid[i][j-1]==1){
           return -1;
       }
       
       if(grid[i][j]==1) return dfs(grid,i+1,j+1);
       
       else return dfs(grid,i+1,j-1);
       
   }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>ans(n,-1);
        
        for(int col=0;col<n;col++){
            ans[col] = dfs(grid,0,col);
        }
        
        return ans;
        
    }
};