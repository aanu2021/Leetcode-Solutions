class Solution {
public:
    
    /*
    
    T.C : O(M*N*K)
    S.C : O(M*N)
    
    */
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        
        dist[0][0] = 0;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        int level = 0;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int x=curr.first;
                int y=curr.second;
                
                if(x==m-1 && y==n-1) return level;
                
                for(int dir=0;dir<4;dir++){
                    
                    int x1=x+dx[dir];
                    int y1=y+dy[dir];
                    
                    if(x1>=0 && y1>=0 && x1<m && y1<n){
                        
                        if(dist[x1][y1] > dist[x][y] + grid[x1][y1] && dist[x][y] + grid[x1][y1] <= k ){
                            
                            dist[x1][y1] = dist[x][y] + grid[x1][y1];
                            q.push({x1,y1});                       
                            
                        }
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return -1;
        
    }
};