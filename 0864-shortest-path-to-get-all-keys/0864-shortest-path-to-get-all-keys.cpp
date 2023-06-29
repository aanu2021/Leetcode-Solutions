class Solution {
public:
    
    struct Pair{
      
        int x;
        int y;
        int mask;
        
    };
    
    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].length();
        
        int visited[m+1][n+1][70];
        memset(visited,0,sizeof(visited));
        
        queue<Pair>q;
        unordered_map<int,int>ID;
        int K = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '@'){
                    q.push({i,j,0});
                    visited[i][j][0] = 1;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    ID[grid[i][j]-'a'] = K++;
                }
            }
        }
        
        int pathLen = 0;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                auto curr = q.front(); q.pop();
                int x = curr.x;
                int y = curr.y;
                int mask = curr.mask;
                
                if(mask == (1<<K) - 1){
                    return pathLen;
                }
                
                for(int dir=0;dir<4;dir++){
                    
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    int k = mask;
                    
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    
                    if(grid[nx][ny] == '#') continue;
                    
                    if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z'){
                       k |= (1<<ID[grid[nx][ny]-'a']);                   
                    }
                    
                    if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z'){
                        if(!(k&(1<<ID[grid[nx][ny]-'A']))) continue;
                    }
                    
                    if(!visited[nx][ny][k]){
                        visited[nx][ny][k] = 1;
                        q.push({nx,ny,k});
                    }
                    
                }
                
            }
            pathLen++;
        }
        
        return -1;
        
    }
};