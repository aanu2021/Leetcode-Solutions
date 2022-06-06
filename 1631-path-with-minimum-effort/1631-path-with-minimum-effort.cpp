class Solution {
public:
    
    struct Pair{
      
        int x;
        int y;
        int wt;
        
    };
    
    struct comp{
      
        bool operator()(const Pair&x,const Pair&y){
            return x.wt > y.wt;
        }
        
    };
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        pq.push({0,0,0});
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int x=curr.x;
            int y=curr.y;
            int wt=curr.wt;
            
            if(x==m-1 && y==n-1){
                return wt;
            }
            
            if(visited[x][y]==true){
                continue;
            }
            
            visited[x][y]=true;
            
            for(int i=0;i<4;i++){
                
                int x1=x+dx[i];
                int y1=y+dy[i];
                
                if(x1>=0 && x1<m && y1>=0 && y1<n && visited[x1][y1]==false){
                    
                    int dist=abs(grid[x][y]-grid[x1][y1]);
                    
                    pq.push({x1,y1,max(wt,dist)});
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};