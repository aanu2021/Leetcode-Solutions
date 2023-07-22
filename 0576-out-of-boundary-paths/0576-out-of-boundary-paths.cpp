class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    int dp[51][51][51];
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    int func(int row,int col,int move,int m,int n){
        if(move < 0) return 0;
        if(row < 0 || col < 0 || row >= m || col >= n) return 1;
        if(dp[row][col][move] != -1) return dp[row][col][move];
        ll ways = 0LL;
        for(int dir=0;dir<4;dir++){
            int nrow = row + dx[dir];
            int ncol = col + dy[dir];
            ways += (ll)func(nrow,ncol,move-1,m,n);
            ways %= M;
        }
        return dp[row][col][move] = (int)ways;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        int ans = func(startRow,startColumn,maxMove,m,n);
        return ans;
        
    }
};