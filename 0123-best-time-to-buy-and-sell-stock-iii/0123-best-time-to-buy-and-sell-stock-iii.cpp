class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][3][2];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=2;j>=1;j--){
                dp[i][j][1] = max(dp[i+1][j][1],-prices[i]+dp[i+1][j][0]);
                dp[i][j][0] = max(dp[i+1][j][0],prices[i]+dp[i+1][j-1][1]);
            }
        }
        return dp[0][2][1];
    }
};