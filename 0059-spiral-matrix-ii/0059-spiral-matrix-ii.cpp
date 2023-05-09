class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // container to store the spiral order 
        vector<vector<int>>grid(n,vector<int>(n));
        
        int row_start = 0, row_end = n-1, col_start = 0, col_end = n-1;
        int value = 1;
        
        while(row_start <= row_end && col_start <= col_end){
            
            // top most row -> left to right traversal
            
            for(int col=col_start;col<=col_end;col++){
                if(value <= n*n){
                    grid[row_start][col] = value++;
                }
            }
            
            row_start++;
            
            // right most col -> top to bottom traversal
            
            for(int row=row_start;row<=row_end;row++){
                if(value <= n*n){
                    grid[row][col_end] = value++;
                }
            }
            
            col_end--;
            
            // bottom most row -> right to left traversal
            
            for(int col=col_end;col>=col_start;col--){
                if(value <= n*n){
                    grid[row_end][col] = value++;
                }
            }
            
            row_end--;
            
            // left most col -> bottom to top traversal
            
            for(int row=row_end;row>=row_start;row--){
                if(value <= n*n){
                    grid[row][col_start] = value++;
                }
            }
            
            col_start++;
            
        }
        
        return grid;
    }
};