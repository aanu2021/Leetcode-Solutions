class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        
        int m = grid.size();
        int n = grid[0].size();
        int lowRow = 0, highRow = m-1;
        int idxRow = -1;
        
        while(lowRow <= highRow){
            
            int midRow = (lowRow + highRow)/2;
            
            if(grid[midRow][0] <= target){
                idxRow = midRow;
                lowRow = midRow + 1;
            }
            else{
                highRow = midRow - 1;
            }
            
        }
        
        if(idxRow == -1) return false;
        
        int lowCol = 0, highCol = n-1;
        int idxCol = -1;
        
        while(lowCol <= highCol){
            
            int midCol = (lowCol + highCol)/2;
            
            if(grid[idxRow][midCol] == target) return true;
            
            if(grid[idxRow][midCol] > target){
                highCol = midCol - 1;
            }
            else{
                lowCol = midCol + 1;
            }
            
        }
        
        return false;
    }
};