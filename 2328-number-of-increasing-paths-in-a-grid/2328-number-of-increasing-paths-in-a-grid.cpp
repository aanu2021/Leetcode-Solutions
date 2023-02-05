class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    ll dp[1002][1002];
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    ll func(vector<vector<int>>&grid,int i,int j,int m,int n,int prev){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] <= prev) return 0LL;
        if(dp[i][j] != -1LL) return dp[i][j];
        
        ll ways = 1LL;
        for(int dir = 0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            ways += func(grid,ni,nj,m,n,grid[i][j]);
            ways %= M;
        }
        
        return dp[i][j] = ways;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        ll answer = 0LL;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    func(grid,i,j,m,n,-1);
                }
                answer += dp[i][j];
                answer %= M;
            }
        }
        return answer;
    }
};