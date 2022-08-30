class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
         
        int n=grid.size();
        
        for(int i=0;i<n;++i){
            
            for(int j=0;j<i;++j){
                
                swap(grid[i][j],grid[j][i]);
                
            }
            
        }
        
        for(int i=0;i<n;++i){
            
            reverse(grid[i].begin(),grid[i].end());
            
        }
        
    }
};