struct Pair{
  
    int i;
    int j;
    int wt;
    
};

class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        deque<Pair>q;
        
        q.push_back({0,0,0});
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop_front();
            
            int i=curr.i;
            int j=curr.j;
            int wt=curr.wt;
            
            if(visited[i][j]) continue;
            
            if(i==m-1 && j==n-1) return wt;
            
            visited[i][j] = true;
            
            for(int dir=0;dir<4;dir++){
                
                int x1=i+dx[dir];
                int y1=j+dy[dir];
                
                if(x1>=0 && y1>=0 && x1<m && y1<n && visited[x1][y1]==false){
                    
                    if(grid[x1][y1]==1){
                        
                        q.push_back({x1,y1,wt+1});
                        
                    }
                    
                    else{
                        
                        q.push_front({x1,y1,wt});
                        
                    }
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};