class Solution {
public:
    
    typedef long long ll;
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int m = primes.size();
        vector<ll>pointer(m,0LL);
        
        vector<ll>dp(n,0LL);
        dp[0] = 1LL;
        
        for(int i=1;i<n;i++){
            ll mini = LONG_MAX;
            for(int j=0;j<m;j++){
                mini = min(mini,dp[pointer[j]]*primes[j]);
            }
            dp[i] = mini;
            for(int j=0;j<m;j++){
                if((primes[j]*dp[pointer[j]])==mini){
                    pointer[j]++;
                }
            }
        }
        
        return dp[n-1];
        
    }
};