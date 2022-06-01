class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        
        queue<pair<int,int>>q;
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int x=curr.first;
            int y=curr.second;
            
            for(int k=0;k<4;k++){
                
                int x1=x+dx[k];
                int y1=y+dy[k];
                
                if(x1>=0 && x1<m && y1>=0 && y1<n){
                    
                    if(dis[x1][y1]>dis[x][y]+1){
                        dis[x1][y1]=dis[x][y]+1;
                        q.push({x1,y1});
                    }
                    
                }
                
            }
            
        }
        
        return dis;
        
    }
};