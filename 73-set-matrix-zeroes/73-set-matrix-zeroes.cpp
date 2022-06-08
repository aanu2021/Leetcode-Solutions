class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        bool row=false,col=false;
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                row=true;
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i]==0){
                col=true;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                
                if(grid[i][j]==0){
                    grid[0][j]=0;
                    grid[i][0]=0;
                }
                
            }
        }
        
        
        for(int i=1;i<m;i++){
            
            if(grid[i][0]==0){
                
                for(int j=0;j<n;j++){
                    grid[i][j]=0;
                }
                
            }
            
        }
        
        
        for(int i=1;i<n;i++){
            
            if(grid[0][i]==0){
                
                for(int j=0;j<m;j++){
                    grid[j][i]=0;
                }
                
            }
            
        }
        
        
        if(row){
            
            for(int i=0;i<m;i++){
                grid[i][0]=0;
            }
            
        }
        
        
        if(col){
            
            for(int i=0;i<n;i++){
                grid[0][i]=0;
            }
            
        }
        
    }
};