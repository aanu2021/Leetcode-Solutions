class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],j*dp[i-j]);
                dp[i]=max(dp[i],j*(i-j));
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<dp[i]<<" ";
        // }cout<<"\n";
        return dp[n];
    }
};