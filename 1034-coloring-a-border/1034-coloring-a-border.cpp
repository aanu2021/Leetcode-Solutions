class Solution {
public:
    
    int m,n;
    
    int val=100000;
    
    void func(vector<vector<int>>&grid,int i,int j,int prev){
        
        if(i<0 || j<0 || i>=m ||j>=n || grid[i][j]!=prev || grid[i][j]==val || grid[i][j]==-prev){
            return;
        }
        
        int cnt=0;
        
        grid[i][j]=-prev;
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        for(int k=0;k<4;k++){
            
            int x=i+dx[k];
            int y=j+dy[k];
            
            if(x>=0 && x<m && y>=0 && y<n && ( abs(grid[x][y])==prev || grid[x][y]==val )){
                cnt++;
            }
            
        }
        
        if(cnt==4){
            
            grid[i][j]=val;
            
        }
        
        func(grid,i+1,j,prev);
        func(grid,i-1,j,prev);
        func(grid,i,j+1,prev);
        func(grid,i,j-1,prev);
        
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        m=grid.size();
        n=grid[0].size();
        
        int prev=grid[row][col];
        
        if(grid[row][col]==color){
            return grid;
        }
        
        func(grid,row,col,prev);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-prev){
                    grid[i][j]=color;
                }
                if(grid[i][j]==val){
                    grid[i][j]=prev;
                }
            }
        }
        
        return grid;
        
    }
};