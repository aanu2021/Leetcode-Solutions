class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int kInversePairs(int n, int k) {
        vector<vector<ll>>dp(n+1, vector<ll>(k+1, 0LL));
        dp[1][0] = 1LL;
        for(int i=2;i<=n;i++){
            vector<ll>prev(k+1, 0LL);
            for(int j=0;j<=k;j++){
                prev[j] = dp[i-1][j];
            }
            for(int j=1;j<=k;j++){
                prev[j] += prev[j-1];
                prev[j] %= M;
            }
            for(int j=0;j<=k;j++){
                 // Actual Optimization...
                int jj = j-i;
                if(jj >= 0){
                    dp[i][j] += prev[j];
                    dp[i][j] -= prev[jj];
                    dp[i][j] += M;
                    dp[i][j] %= M;
                }
                else{
                    dp[i][j] += prev[j];
                    dp[i][j] %= M;
                }
                /*
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= M;
                for(int m=i-1;m>=1;m--){
                    dp[i][j] += (j-i+m >= 0 ? dp[i-1][j-i+m] : 0LL);
                    dp[i][j] %= M;
                }
                */
            }
        }
        return dp[n][k];
    }
};

/*

1 2 3 4  
    
i = 5  
    
j = 3
   
    
3-5+1  (1)
3-5+2  (2)
3-5+3  (3)
3-5+4  (4)
3-5+5  (5)    
    
  
i = 4
j = 5

dp[3][5]    
dp[3][4]   
dp[3][3]
dp[3][2]

j-(i-1) = 2
    
1 2 3  4
    
    1 2 4 3
    
    1 4 2 3
    
    4 1 2 3
    
    

i = 5
j = 3
    
dp[4][3] 
dp[4][2]
dp[4]
    
1 2 3 4     5    
    
    1 2 3 4 5
    
    1 2 3 5 4
    
    1 2 5 3 4
    
    1 5 2 3 4
    
    5 1 2 3 4
    
*/    