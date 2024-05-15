struct Pair{
    int x;
    int y;
    int wt;
};

struct comp{
   bool operator()(const Pair&x, const Pair&y){
       return x.wt > y.wt;
   }  
};

class Solution {
public:
    
    const int INF = 1000000000;
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>M(n, vector<int>(n, INF));
        priority_queue<Pair,vector<Pair>,comp>pq;
        vector<vector<int>>dist(n, vector<int>(n, INF));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    M[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                    if(M[nx][ny] > M[x][y] + 1){
                        M[nx][ny] = M[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        pq.push({0, 0, -M[0][0]});
        dist[0][0] = -M[0][0];
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int x = curr.x;
            int y = curr.y;
            int wt = curr.wt;
            if(dist[x][y] != wt) continue;
            if(x == n-1 && y == n-1) return -wt;
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                    int nextWt = min(-wt, M[nx][ny]);
                    if(dist[nx][ny] > -nextWt){
                        dist[nx][ny] = -nextWt;
                        pq.push({nx, ny, -nextWt});
                    }
                }
            }
        }
        return -1;
    }
};