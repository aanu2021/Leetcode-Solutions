class Solution {
public:
    
    /*
    
         Time Complexity  : O(M*logN) 
         Space Complexity : O(1)
    
    */
    
    /*
    
       First try to fix either the row or the column , after
       fixing the column , here we fix the column (do a binary 
       search on it) and then find the maximum element out of the
       column . Finally it is required to check the maximum 
       element of that column (cell) with its adjacent neighbours
       , if it is greater than both of them , then return that 
       particular cell , otherwise check recursively for the 
       right / left half .
    
    */
    
    /*
    
       Algorithm :
       
       low = 0  high = n-1
       
       mid_col = (low + high) / 2
       
       (max_row,mid_col) is the cell containing maximum element out of that column.
       
       if(grid[max_row][mid_col] > grid[max_row][mid_col-1] && grid[max_row][mid_col] > grid[max_row][mid_col+1]){
       
           print (max_row , mid_col);
          
       }
       
       else if(grid[max_row][mid_col] < grid[max_row][mid_col-1])       {
           
           high = mid_col - 1;
       
       } 
       
       else{
       
           low = mid_col + 1;
       
       }
      
    
    */
    
    vector<int> findPeakGrid(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int low = 0,high = n-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            int row=0;
            
            for(int i=0;i<m;++i){
                if(grid[row][mid]<grid[i][mid]){
                    row=i;
                }
            }
            
            if((mid==0 || grid[row][mid] > grid[row][mid-1]) && (mid==n-1 || grid[row][mid] > grid[row][mid+1])){
                
                return {row,mid};
                
            }
            
            else if(mid>0 && grid[row][mid] < grid[row][mid-1]){
                
                high = mid - 1;
                
            }
            
            else{
                
                low = mid + 1;
                
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
    