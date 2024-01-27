class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int kInversePairs(int n, int k) {
        vector<vector<ll>>dp(n+1, vector<ll>(k+1, 0LL));
        dp[1][0] = 1LL;
        for(int i=2;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= M;
                for(int m=i-1;m>=1;m--){
                    dp[i][j] += (j-i+m >= 0 ? dp[i-1][j-i+m] : 0LL);
                    dp[i][j] %= M;
                }
            }
        }
        return dp[n][k];
    }
};


  