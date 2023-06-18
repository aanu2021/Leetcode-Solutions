class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll dp[1002][1002];
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    ll func(vector<vector<int>>&grid,int i,int j,int m,int n){
        
        if(i < 0 || j < 0 || i >= m || j >= n) return 0LL;
        
        if(dp[i][j] != -1LL) return dp[i][j];
        
        ll ways = 1LL;
        
        for(int dir=0;dir<4;dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > grid[i][j]){
                ways += func(grid,nx,ny,m,n);
                ways %= M;
            }
        }
        
        return dp[i][j] = ways;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        memset(dp,-1LL,sizeof(dp));
        
        ll answer = 0LL;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer += func(grid,i,j,m,n);
                answer %= M;
            }
        }
        
        return answer;
        
    }
};