class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[202][202][202][3];
    
    int func(int z, int o, int conse, int last, int n, int zero, int one, int limit){
        if(conse > limit) return 0;
        if(z > zero) return 0;
        if(o > one) return 0;
        if(z + o == n){
            return 1;
        }
        if(dp[z][o][conse][last] != -1) return dp[z][o][conse][last];
        ll ways = 0LL;
        ways += (ll)func(z+1, o, (last == 0 ? conse + 1 : 1), 0, n, zero, one, limit);
        ways %= M;
        ways += (ll)func(z, o+1, (last == 1 ? conse + 1 : 1), 1, n, zero, one, limit);
        ways %= M;
        return dp[z][o][conse][last] = (int)ways;
    }
    
    int numberOfStableArrays(int zero, int one, int limit) {
        int n = zero + one;
        int ans = 0;
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                for(int k=0;k<=limit;k++){
                    dp[i][j][k][0] = -1;
                    dp[i][j][k][1] = -1;
                    dp[i][j][k][2] = -1;
                }
            }
        }
        ans = func(0, 0, 0, 2, n, zero, one, limit);
        return ans;
    }
};

