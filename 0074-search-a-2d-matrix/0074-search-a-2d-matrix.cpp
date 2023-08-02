class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int row = 0, col = n-1;
        
        while(row >= 0 && row < m && col >= 0 && col < n){
            if(grid[row][col] == target){
                return true;
            }
            if(grid[row][col] > target){
                col--;
            }
            else{
                row++;
            }
        }
        
        return false;
        
    }
};