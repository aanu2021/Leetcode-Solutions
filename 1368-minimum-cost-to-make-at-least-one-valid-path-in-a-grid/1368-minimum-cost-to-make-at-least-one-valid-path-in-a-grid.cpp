/*

Dijkstra's Algorithm : O(E*logV)

Time Complexity  : O(4*M*N*log(M*N))
Space Complexity : O(M*N)

*/


struct Pair{
    
  int i;
  int j;
  int wt;
    
};

class Solution {
public:

    
    int minCost(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        deque<Pair>q;
        
        q.push_back({0,0,0});
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int val[4]={1,2,3,4};
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop_front();
            
            int i=curr.i;
            int j=curr.j;
            int wt=curr.wt;
            
            if(visited[i][j]){
                continue;
            }
            
            visited[i][j] = true;
            
            if(i==m-1 && j==n-1){
                return wt;
            }
            
            for(int dir=0;dir<4;dir++){
                
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                int nwt = wt + (grid[i][j]!=val[dir]);
                
                int factor=(grid[i][j]!=val[dir]);
                
                if(ni>=0 && nj>=0 && ni<m && nj<n && visited[ni][nj]==false){
                    
                    if(factor==0){
                        q.push_front({ni,nj,nwt});
                    }
                    else{
                        q.push_back({ni,nj,nwt});
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