class Solution {
public:
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    int fire_time[305][305];
    
    int dist[305][305];
    
    int time_reach_dest(int idle,vector<vector<int>>&grid){
        
        int m=grid.size();
        int n=grid[0].size();
        
        if(fire_time[0][0]<=idle){
            return 1e9 + 1;
        }
        
         for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dist[i][j]=1e9;
            }
        }
        
        queue<pair<int,int>>q;
        
        dist[0][0]=idle;
        
        q.push({0,0});
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int i=curr.first;
            int j=curr.second;
            
            for(int dir=0;dir<4;dir++){
                
                int ni=i+dx[dir];
                int nj=j+dy[dir];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]!=2){
                    
                    if(dist[ni][nj] > dist[i][j] + 1){
                        
                        dist[ni][nj] = 1 + dist[i][j];
                        
                        if(ni==m-1 && nj==n-1 && dist[ni][nj]<=fire_time[ni][nj]){
                            
                            return dist[ni][nj];
                            
                        }
                        
                        if(dist[ni][nj]>=fire_time[ni][nj]){
                            
                            continue;
                            
                        }
                        
                        q.push({ni,nj});
                        
                    }
                    
                }
                
            }
            
        }
        
        return 1e9 + 1;
        
    }
    
    int func(vector<vector<int>>&grid){
        
        int m=grid.size();
        int n=grid[0].size();
        
//         if(fire_time[m-1][n-1]>=1e9){
            
//             if(time_reach_dest(0,grid)>=1e9){
//                 return -1;
//             }
            
//             else{
//                 return 1e9;
//             }
            
//         }
        
        int ans=-1,low=0,high=m*n+1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(time_reach_dest(mid,grid)<=fire_time[m-1][n-1]){
                
                ans=mid;
                low=mid+1;
                
            }
            
            else{
                
                high=mid-1;
                
            }
            
        }
        
        if(ans>=(m*n)+1){
            return 1e9;
        }
        
        else{
            return ans;
        }
        
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                fire_time[i][j]=1e9;
                dist[i][j]=1e9;
            }
        }
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    fire_time[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            
            int i=curr.first;
            int j=curr.second;
            
            for(int dir=0;dir<4;dir++){
                
                int ni=i+dx[dir];
                int nj=j+dy[dir];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==0){
                    
                    if(fire_time[ni][nj] > fire_time[i][j] + 1){
                        
                        fire_time[ni][nj] = 1 + fire_time[i][j];
                        
                        q.push({ni,nj});
                        
                    }
                    
                }
                
            }
            
        }
        
        return func(grid);
        
    }
};