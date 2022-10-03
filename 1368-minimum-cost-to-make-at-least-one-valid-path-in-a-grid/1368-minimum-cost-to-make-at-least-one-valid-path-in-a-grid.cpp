/*

Dijkstra's Algorithm : O(E*logV)

Time Complexity  : O(4*M*N*log(M*N))
Space Complexity : O(M*N)

*/

/*

0-1 BFS Algorithm : O(E + V)  [Applicable for 0/1 Edge Weights]

Time Complexity  : O(M*N*4 + M*N)
Space Complexity : O(M*N)

*/

struct Pair{
  
    int x;
    int y;
    int wt;
    
};

class Solution {
public:

    struct comp{
      
        bool operator()(const Pair&x,const Pair&y){
            
            return x.wt > y.wt;
            
        }
        
    };
    
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        pq.push({0,0,0});
        
        int dx[4]  = {0,0,1,-1};
        int dy[4]  = {1,-1,0,0};
        int val[4] = {1,2, 3,4};
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int x = curr.x;
            int y = curr.y;
            int wt = curr.wt;
            
            if(x==m-1 && y==n-1){
                
                return wt;
                
            }
            
            if(visited[x][y]) continue;
            
            visited[x][y] = true;
            
            for(int dir=0;dir<4;dir++){
                
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    
                    if(!visited[nx][ny]){
                        
                        int nwt = wt + (grid[x][y]!=val[dir]);
                        
                        pq.push({nx,ny,nwt});
                        
                    }
                    
                }
                
            }
            
        }
        
        return -1;
        
    }
};

/*

(-1,0) -> North 
( 1,0) -> South
(0,-1) -> Left
(0, 1) -> Right

0 , 0  , 1 , -1
1 , -1 , 0 ,  0
1    2   3    4   

*/