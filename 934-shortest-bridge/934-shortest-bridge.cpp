class Solution {
public:
    
    queue<pair<int,int>>q;
    
    void dfs(vector<vector<int>>&grid,int i,int j){
        
        int n=grid.size();
        
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0){
            return;
        }
        
        grid[i][j]=0;
        
        q.push({i,j});
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        bool flag=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    flag=true;
                    break;
                }
            }
            if(flag==true){
                break;
            }
        }
        
        
        int level=0;
        
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int x=curr.first;
                int y=curr.second;
                
                if(visited[x][y]==true){
                    continue;
                }
                
                visited[x][y]=true;
                
                for(int k=0;k<4;k++){
                    
                    int x1=x+dx[k];
                    int y1=y+dy[k];
                    
                    if(x1>=0 && x1<n && y1>=0 && y1<n){
                        
                        if(grid[x1][y1]==0){
                            
                            q.push({x1,y1});
                            
                        }
                        
                        else if(grid[x1][y1]==1){
                            
                            return level;
                            
                        }
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return -1;
        
    }
};