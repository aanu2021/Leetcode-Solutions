class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        
        int dx[8]={0,0,1,-1,1,1,-1,-1};
        int dy[8]={1,-1,0,0,1,-1,1,-1};
        
        dist[0][0]=1;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int x=curr.first;
            int y=curr.second;
            
            for(int i=0;i<8;i++){
                
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                    
                    if(dist[nx][ny]>dist[x][y]+1){
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                    }
                    
                }
                
            }
            
        }
        
        if(dist[n-1][n-1]>=1e9){
            return -1;
        }else{
            return dist[n-1][n-1];
        }
        
    }
};