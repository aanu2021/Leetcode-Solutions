class Solution {
public:
    
    struct Pair{
        
        int i;
        int j;
        int wt;
        
    };
    
    struct comp{
      
        bool operator()(const Pair&x,const Pair&y){
            return x.wt > y.wt;
        }
        
    };
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        // priority_queue<Pair,vector<Pair>,comp>pq;
        
        deque<Pair>q;
        
        q.push_back({0,0,0});
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop_front();
            
            int i = curr.i;
            int j = curr.j;
            int wt = curr.wt;
            
            if(visited[i][j]) continue;
            
            visited[i][j] = true;
            
            if(i==m-1 && j==n-1) return wt;
            
            for(int dir=0;dir<4;dir++){
                
                int ni = i+dx[dir];
                int nj = j+dy[dir];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    
                    if(visited[ni][nj]==false){
                        
                        if(grid[ni][nj]==0){
                            q.push_front({ni,nj,wt});
                        }else{
                            q.push_back({ni,nj,wt+grid[ni][nj]});
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};