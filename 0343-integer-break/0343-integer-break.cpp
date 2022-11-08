class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        if(n==5) return 6;
        if(n==6) return 9;
        vector<int>dp(n+1,0);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 4;
        dp[5] = 6;
        dp[6] = 9;
        for(int i=7;i<=n;i++){
            dp[i]=3*dp[i-3];
        }
        return dp[n];
    }
};