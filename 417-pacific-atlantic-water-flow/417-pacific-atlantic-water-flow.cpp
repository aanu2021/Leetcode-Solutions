class Solution {
public:
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&visited){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]){
            return;
        }
        
        visited[i][j]=true;
        
        for(int dir=0;dir<4;dir++){
            
            int ni=i+dx[dir];
            int nj=j+dy[dir];
            
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]>=grid[i][j] && visited[ni][nj]==false){
                
                dfs(grid,ni,nj,visited);
                
            }
            
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        
        
        // For Pacific Ocean //
        
        for(int i=0;i<n;++i){
            
            if(pacific[0][i]==false){
                
                dfs(grid,0,i,pacific);
                
            }
            
        }
        
        for(int i=1;i<m;++i){
            
            if(pacific[i][0]==false){
                
                dfs(grid,i,0,pacific);
                
            }
            
        }
        
        
        // For Atlantic Ocean //
        
        
        for(int i=0;i<m;++i){
            
            if(atlantic[i][n-1]==false){
                
                dfs(grid,i,n-1,atlantic);
                
            }
            
        }
        
        
        for(int i=0;i<n-1;++i){
            
            if(atlantic[m-1][i]==false){
                
                dfs(grid,m-1,i,atlantic);
                
            }
            
        }
        
        
        vector<vector<int>>ans;
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(pacific[i][j] && atlantic[i][j]){
                    
                    ans.push_back({i,j});
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};