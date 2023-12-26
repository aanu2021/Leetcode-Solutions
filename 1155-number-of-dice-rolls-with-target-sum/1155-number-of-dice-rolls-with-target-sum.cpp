class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll dp[32][1002];
    
    ll func(int i,int target,int n,int k){
        if(target < 0) return 0LL;
        if(i == n) {
            if(target == 0) return 1LL;
            else return 0LL;
        }
        if(dp[i][target] != -1LL) return dp[i][target];
        ll ways = 0LL;
        for(int num=1;num<=k;num++){
            if(target >= num){
                ways += func(i+1,target-num,n,k);
                ways %= M;
            }
        }
        return dp[i][target] = ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1LL,sizeof(dp));
        ll ans = func(0,target,n,k);
        return ans;
    }
};