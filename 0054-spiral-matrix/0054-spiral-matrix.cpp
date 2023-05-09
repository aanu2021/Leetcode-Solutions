class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int pos = 0;
        int row_start = 0, col_start = 0, row_end = m-1, col_end = n-1;
        
        vector<int>answer;
        
        while(row_start <= row_end && col_start <= col_end){
            
            // up left to right
            
            for(int col=col_start;col<=col_end;col++){
                if(pos < m*n){
                    answer.push_back(grid[row_start][col]);
                    pos++;
                }
            }
            
            row_start++;
            
            // right top to bottom
            
            for(int row=row_start;row<=row_end;row++){
                if(pos < m*n){
                    answer.push_back(grid[row][col_end]);
                    pos++;
                }
            }
            
            col_end--;
            
            // bottom right to left
            
            for(int col=col_end;col>=col_start;col--){
                if(pos < m*n){
                    answer.push_back(grid[row_end][col]);
                    pos++;
                }
            }
            
            row_end--;
            
            // left bottom to top
            
            for(int row=row_end;row>=row_start;row--){
                if(pos < m*n){
                    answer.push_back(grid[row][col_start]);
                    pos++;
                }
            }
            
            col_start++;
            
        }
        
        return answer;
        
    }
};