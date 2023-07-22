class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int findPaths(int m, int n, int move, int row, int col) {
        
        if(move == 0) return 0;
        
        vector<vector<ll>>dp(m,vector<ll>(n,0));
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int dir=0;dir<4;dir++){
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if(ni < 0 || nj < 0 || ni >= m || nj >= n){
                        dp[i][j]++;
                    }
                }
            }
        }
        
        ll totalSum = 0LL;
        totalSum += dp[row][col];
        totalSum %= M;
        
        for(int mo=2;mo<=move;mo++){
            vector<vector<ll>>dp2(m,vector<ll>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(int dir=0;dir<4;dir++){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                            dp2[i][j] += dp[ni][nj];
                            dp2[i][j] %= M;
                        }
                    }
                }
            }
            dp = dp2;
            totalSum += dp[row][col];
            totalSum %= M;
        }
        
        return (int)totalSum;
        
    }
};