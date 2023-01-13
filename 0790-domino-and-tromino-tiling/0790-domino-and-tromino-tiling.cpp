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

    int numTilings(int n) {
        vector<ll>dp(n+1,0LL);
        if(n <= 2) return n;
        dp[0] = 1LL;
        dp[1] = 1LL;
        dp[2] = 2LL;
        for(ll i=3;i<=n;i++){
            dp[i] = add(mul(2LL,dp[i-1]),dp[i-3]);
        }
        return dp[n];
    }
};

/*

Recurrence :

dp[n] = dp[n-1] + dp[n-2] + 2*(dp[n-3] + dp[n-4] + ... + dp[0])

dp[n] = dp[n-1] + dp[n-3] + { dp[n-2] + dp[n-3] + 2*(dp[n-4] + dp[n-5] + ... + dp[0])}

dp[n] = dp[n-1] + dp[n-3] + dp[n-1]

dp[n] = 2*dp[n-1] + dp[n-3]

T.C : O(N)
S.C : O(N) -> O(1) 

*/