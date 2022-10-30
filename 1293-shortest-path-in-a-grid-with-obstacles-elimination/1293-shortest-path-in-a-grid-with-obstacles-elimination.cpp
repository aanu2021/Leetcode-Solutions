class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        
        dist[0][0] = 0;
        
        q.push({0,0});
        
        int lvl = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                if(x==m-1 && y==n-1) return lvl;
                
                for(int dir=0;dir<4;dir++){
                    
                    int nx = x+dx[dir];
                    int ny = y+dy[dir];
                    
                    if(nx<0 || nx>=m || ny<0 || ny>=n){
                        continue;
                    }
                    
                    if(dist[nx][ny] > dist[x][y] + grid[nx][ny] && dist[x][y] + grid[nx][ny] <= k){
                        
                        dist[nx][ny] = dist[x][y] + grid[nx][ny];
                        
                        q.push({nx,ny});
                        
                    }
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
};