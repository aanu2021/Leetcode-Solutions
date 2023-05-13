class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<ll>dp(high+1,0LL);
        
        dp[0] = 1LL;
        
        for(int i=1;i<=high;i++){
            if(i-zero >= 0){
                dp[i] += dp[i-zero];
                dp[i] %= M;
            }
            if(i-one >= 0){
                dp[i]  += dp[i-one];
                dp[i] %= M;
            }
        }
        
        ll sum = 0LL;
        for(int i=low;i<=high;i++){
            sum += dp[i];
            sum %= M;
        }
        
        return sum;
        
    }
};

/*

zero = 1
one = 2
    
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 3   

*/
    