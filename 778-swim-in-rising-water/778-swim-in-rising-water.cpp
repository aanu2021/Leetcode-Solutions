class Solution {
public:
    
    struct Pair{
      
        int r;
        int c;
        int val;
        
    };
    
    struct comp{
      
        bool operator()(const Pair&x,const Pair&y){
            
            return x.val > y.val;
            
        }
        
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        pq.push({0,0,grid[0][0]});
        
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int x=curr.r;
            int y=curr.c;
            int wt=curr.val;
            
            if(visited[x][y]==true){
                continue;
            }
            
            visited[x][y]=true;
            
            if(x==n-1 && y==n-1){
                return wt;
            }
            
            for(int i=0;i<4;i++){
                
                int x1=x+dx[i];
                int y1=y+dy[i];
                
                if(x1>=0 && x1<n && y1>=0 && y1<n){
                    
                    if(visited[x1][y1]==true){
                        continue;
                    }
                    
                    pq.push({x1,y1,max(wt,grid[x1][y1])});
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};