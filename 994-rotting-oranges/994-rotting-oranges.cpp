class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int fresh=0;
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==2){
                    
                    q.push({i,j});
                    
                }
                
                else if(grid[i][j]==1){
                    
                    fresh++;
                    
                }
                
            }
            
        }
        
        if(fresh==0){
            return 0;
        }
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        int time=0;
        
        while(!q.empty()){
            
            if(fresh==0){
                
                return time;
                
            }
            
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
                    
                    if(x1>=0 && x1<m && y1>=0 && y1<n){
                        
                        if(grid[x1][y1]==1){
                            
                            grid[x1][y1]=2;
                            fresh--;
                            q.push({x1,y1});
                            
                        }
                        
                    }
                    
                }
                
            }
            
            time++;
            
        }
        
        return -1;
        
    }
};