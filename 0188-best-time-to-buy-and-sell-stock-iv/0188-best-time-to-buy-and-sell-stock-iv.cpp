class Solution {
public:
    
    int func(vector<int>&prices,int i,int k,int bought,int n,vector<vector<vector<int>>>&dp){
        if(i==n) return 0;
        if(dp[i][k][bought]!=-1) return dp[i][k][bought];
        int ans = func(prices,i+1,k,bought,n,dp);
        if(bought){
            ans = max(ans,-prices[i] + func(prices,i+1,k,0,n,dp));
        }else{
            if(k>0){
                ans = max(ans,prices[i] + func(prices,i+1,k-1,1,n,dp));
            }
        }
        return dp[i][k][bought] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][k+1][2];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=k;j>=1;j--){
                dp[i][j][1] = max(dp[i+1][j][1],-prices[i]+dp[i+1][j][0]);
                dp[i][j][0] = max(dp[i+1][j][0],prices[i]+dp[i+1][j-1][1]);
            }
        }
        return dp[0][k][1];
    }
};