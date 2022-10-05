class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        
        int fresh=0,rotten=0;
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(grid[i][j]==1){
                    
                    fresh++;
                    
                }
                
                if(grid[i][j]==2){
                    
                    rotten++;
                    
                    q.push({i,j});
                    
                    visited[i][j] = true;
                    
                }
                
            }
            
        }
        
        if(fresh==0){
            
            return 0;
            
        }
        
        
        int timer=0;
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            
            int sz = q.size();
            
            if(fresh==0){
                return timer;
            }
            
            while(sz--){
                
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                
                for(int dir=0;dir<4;dir++){
                    
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && visited[nx][ny]==false){
                        
                        visited[nx][ny] = true;
                        
                        fresh--;
                        
                        q.push({nx,ny});
                        
                    }
                    
                }
                
            }
            
            timer++;
            
        }
        
        return -1;
        
    }
};