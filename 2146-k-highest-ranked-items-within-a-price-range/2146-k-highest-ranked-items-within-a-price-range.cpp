class Solution {
public:
    
    struct Pair{
      
        int r;
        int c;
        int price;
        int dis;
        
    };
    
    struct comp{
        
      bool operator()(const Pair&x,const Pair&y){
          
          if(x.dis!=y.dis){
              return x.dis>y.dis;
          }
          
          if(x.price!=y.price){
              return x.price>y.price;
          }
          
          if(x.r!=y.r){
              return x.r>y.r;
          }
          
          return x.c>y.c;
          
      }  
        
    };
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        
        dis[start[0]][start[1]]=0;
        
        queue<pair<int,int>>q;
        
        q.push({start[0],start[1]});
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int x=curr.first;
            int y=curr.second;
            
            for(int i=0;i<4;i++){
                
                int x1=x+dx[i];
                int y1=y+dy[i];
                
                if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]!=0){
                    
                    if(dis[x1][y1]>dis[x][y]+1){
                        
                        dis[x1][y1]=dis[x][y]+1;
                        q.push({x1,y1});
                        
                    }
                    
                }
                
            }
            
        }
  
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]>1 && dis[i][j]<1e9 && grid[i][j]>=pricing[0] && grid[i][j]<=pricing[1]){
                    
                    pq.push({i,j,grid[i][j],dis[i][j]});
                    
                }
                
            }
            
        }
        
        
        vector<vector<int>>result;
        
        while(!pq.empty() && k>0){
            
            auto curr=pq.top();
            pq.pop();
            
            result.push_back({curr.r,curr.c});
            
            k--;
            
        }
        
        return result;
        
    }
};