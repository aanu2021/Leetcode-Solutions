class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>>q;
        
        int fresh=0,rotten=0;
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(grid[i][j]==1){
                    
                    fresh++;
                    
                }
                
                else if(grid[i][j]==2){
                    
                    rotten++;
                    
                    q.push({i,j});
                    
                }
                
            }
            
        }
        
        if(fresh==0){
            
            return 0;
            
        }
        
        
        int timer=0;
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int i=curr.first;
                int j=curr.second;
                
                
                for(int dir=0;dir<4;dir++){
                    
                    int ni=i+dx[dir];
                    int nj=j+dy[dir];
                    
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        
                        grid[ni][nj]=0;
                        
                        fresh--;
                        
                        q.push({ni,nj});
                        
                    }
                    
                }
                
            }
            
            timer++;
            
        }
        
        return fresh==0 ? timer-1 : -1;
        
    }
};