class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int startRow = 0, endRow = m-1;
        int row = -1;
        
        while(startRow <= endRow){
            int midRow = (startRow + endRow)/2;
            if(grid[midRow][0] <= target){
                row = midRow;
                startRow = midRow + 1;
            }
            else{
                endRow = midRow - 1;
            }
        }
        
        if(row == -1) return false;
        
        int startCol = 0, endCol = n-1;
        
        while(startCol <= endCol){
            int midCol = (startCol + endCol)/2;
            if(grid[row][midCol] == target){
                return true;
            }
            else if(grid[row][midCol] > target){
                endCol = midCol - 1;
            }
            else{
                startCol = midCol + 1;
            }
        }
        
        return false;
        
    }
};