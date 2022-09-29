class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int low_col = 0 , high_col = n-1;
        
        while(low_col <= high_col){
            
            int mid_col = (low_col + high_col)/2;
            
            int max_row = 0;
            
            for(int i=0;i<m;++i){
                
                if(grid[max_row][mid_col] < grid[i][mid_col]){
                    
                    max_row = i;
                    
                }
                
            }
            
            if((mid_col==0 || grid[max_row][mid_col] > grid[max_row][mid_col-1]) && (mid_col==n-1 || grid[max_row][mid_col]>grid[max_row][mid_col+1])){
                
                return {max_row,mid_col};
                
            }
            
            else if(mid_col > 0 && grid[max_row][mid_col-1] > grid[max_row][mid_col]){
                
                high_col = mid_col - 1;
                
            }
            
            else{
                
                low_col = mid_col + 1;
                
            }
            
        }
        
        return {-1,-1};
        
    }
};


/*

10 20 15
21 20 14
7  16 32
    
low_col  = 0
high_col = 0
mid_col  = 0    
    
max_row  = 1    

*/
    