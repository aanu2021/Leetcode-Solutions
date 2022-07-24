class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int i=0,j=n-1;
        
        while(i>=0 && j>=0 && i<m && j<n){
            
            if(grid[i][j]==target){
                return true;
            }
            
            else if(grid[i][j]>target){
                j--;
            }
            
            else{
                i++;
            }
            
        }
        
        return false;
        
    }
};