class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        
        dis[0][0]=0;
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        int level=0;
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int x=curr.first;
                int y=curr.second;
                
                if(x==m-1 && y==n-1){
                    return level;
                }
                
                for(int i=0;i<4;++i){
                    
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<m && ny<n && dis[x][y]+grid[nx][ny]<=k && dis[nx][ny]>dis[x][y]+grid[nx][ny]){
                        
                        dis[nx][ny]=dis[x][y]+grid[nx][ny];
                        q.push({nx,ny});
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return -1;
        
    }
};