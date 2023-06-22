class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        int dp[n+1][2];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--){
            // bought
            dp[i][0] = max(dp[i+1][0],-prices[i] + dp[i+1][1]);
            // sold
            dp[i][1] = max(dp[i+1][1],prices[i] - fee + dp[i+1][0]);
        }
        
        return dp[0][0];
        
    }
};