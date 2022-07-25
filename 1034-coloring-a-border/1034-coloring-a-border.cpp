class Solution {
public:
    
    void func(vector<vector<int>>&grid,int i,int j,int color){
        
       int m=grid.size();
       int n=grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1002 || grid[i][j]==-color || grid[i][j]!=color){
            
            return;
            
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int cnt=0;
        
        for(int dir=0;dir<4;dir++){
            
            int newi=i+dx[dir];
            int newj=j+dy[dir];
            
            if(newi>=0 && newi<m && newj>=0 && newj<n){
                
                if(grid[newi][newj]==color || grid[newi][newj]==-color || grid[newi][newj]==1002){
                    
                    cnt++;
                    
                }
                
            }
            
        }
        
        if(cnt==4){
            
            grid[i][j]=1002;
            
        }
        
        else{
            
            grid[i][j]=-color;
            
        }
        
        func(grid,i+1,j,color);
        func(grid,i-1,j,color);
        func(grid,i,j+1,color);
        func(grid,i,j-1,color);
        
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int prev_color=grid[row][col];
        
        if(grid[row][col]==color){
            
            return grid;
            
        }
        
        func(grid,row,col,prev_color);
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1002){
                    
                    grid[i][j]=prev_color;
                    
                }
                
                else if(grid[i][j]==-prev_color){
                    
                    grid[i][j]=color;
                    
                }
                
            }
            
        }
        
        return grid;
        
    }
};