class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<ll>>dp(goal+1,vector<ll>(n+1,0LL));
        dp[0][0] = 1LL;
        for(int i=1;i<=goal;i++){
            for(int j=1;j<=n;j++){
                ll sum = (dp[i-1][j-1]*(n-j+1));
                sum %= M;
                sum += (dp[i-1][j]*(ll)max(0,j-k));
                sum %= M;
                dp[i][j] = sum;
            }
        }
        return dp[goal][n];
    }
};