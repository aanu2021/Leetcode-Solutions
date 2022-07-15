class Solution {
public:
    
    
    void dfs(vector<vector<int>>&grid,int i,int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        
       // currarea++;
        
        grid[i][j]=0;
        
        dfs(grid,i,j-1);
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int maxarea=0;
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1 && visited[i][j]==false){
                    
                    int currarea=0;
                    
                    stack<pair<int,int>>st;
                    
                    st.push({i,j});
                    
                    while(!st.empty()){
                        
                        auto curr=st.top();
                        st.pop();
                        
                        int x=curr.first;
                        int y=curr.second;
                        
                        if(visited[x][y]==true){
                            continue;
                        }
                        
                        visited[x][y]=true;
                        
                        currarea++;
                        
                        for(int dir=0;dir<4;dir++){
                            
                            int nx=x+dx[dir];
                            int ny=y+dy[dir];
                            
                            if(nx>=0 && ny>=0 && nx<m && ny<n && visited[nx][ny]==false && grid[nx][ny]==1){
                                
                                st.push({nx,ny});
                                
                            }
                            
                        }
                        
                    }
                    
                    maxarea=max(maxarea,currarea);
                    
                }
                
            }
            
        }
        
        return maxarea;
        
    }
};