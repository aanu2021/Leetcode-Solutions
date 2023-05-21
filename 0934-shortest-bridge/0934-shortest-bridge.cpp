class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<bool>>&visited,queue<pair<int,int>>&q)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || visited[i][j]) return;
        
        visited[i][j] = true;
        grid[i][j] = 0;
        q.push({i,j});
        
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                dfs(grid,ni,nj,m,n,visited,q);
            }
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        bool flag = false;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                dfs(grid,i,j,m,n,visited,q);
                flag = true;
                break;
            }
            if(flag) break;
        }
        
        int lvl = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                auto curr = q.front(); q.pop();
                int x = curr.first;
                int y = curr.second;
                
                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                        if(visited[nx][ny]) continue;       
                        if(grid[nx][ny]==1){
                            return lvl;
                        }
                        else{
                            visited[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            lvl++;
        }
        
        return -1;
        
    }
};

