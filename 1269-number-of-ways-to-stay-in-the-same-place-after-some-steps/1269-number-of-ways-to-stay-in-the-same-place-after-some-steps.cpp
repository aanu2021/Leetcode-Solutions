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
    
    ll func(ll index,ll steps,ll n,vector<vector<ll>>&dp){
        if(index < 0 || index >= n) return 0LL;
        if(steps == 0){
            if(index == 0) return 1LL;
            else return 0LL;
        }
        if(dp[index][steps]!=-1) return dp[index][steps];
        ll ans = func(index,steps-1,n,dp);
        ans += func(index+1,steps-1,n,dp);
        ans %= M;
        ans += func(index-1,steps-1,n,dp);
        ans %= M;
        return dp[index][steps] = ans;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(2*steps,arrLen);
        vector<vector<ll>>dp(arrLen+1,vector<ll>(steps+1,-1LL));
        ll ans = func(0LL,(ll)steps,(ll)arrLen,dp);
        return ans;
    }
};