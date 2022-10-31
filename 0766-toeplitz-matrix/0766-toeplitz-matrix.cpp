class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                // Already Visited Till now.
                
                if(grid[i][j]==-1) continue;
                
                int x = i, y = j;
                
                int value = grid[x][y];
                
                while(x<m && y<n){
                    if(grid[x][y]!=value){
                        return false;
                    }
                    grid[x][y]=-1;
                    x++;
                    y++;
                }
                
            }
            
        }
        
        return true;
        
    }
};