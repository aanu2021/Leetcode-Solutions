class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool isPossible(vector<vector<int>>&grid,int m,int n){
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;++i){
            if(grid[0][i] == 0){
                q.push({0,i});
                grid[0][i] = 1;
            }
        }
        
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            if(x == m-1) return true;
            
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if(grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return false;
        
    }
    
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        
        vector<vector<int>>grid(m,vector<int>(n,0));
        
        int low = 0, high = (m*n) - 1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j] = 0;
                }
            }
            
            for(int i=0;i<=mid;i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            
            if(isPossible(grid,m,n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        
        return ans + 1;
        
    }
};