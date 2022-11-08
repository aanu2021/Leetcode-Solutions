class Solution {
public:
    
    int func(vector<int>&prices,int i,int bought,int n,vector<vector<int>>&dp){
        
        if(i>=n) return 0;
        
        if(dp[i][bought]!=-1) return dp[i][bought];
        
        int ans = func(prices,i+1,bought,n,dp);
        
        if(bought){
        
            ans = max(ans,-prices[i]+func(prices,i+1,0,n,dp));
            
        }else{
            
            ans = max(ans,prices[i]+func(prices,i+2,1,n,dp));
            
        }
        return dp[i][bought] = ans;
        
    }
    
    int maxProfit2(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans = func(prices,0,1,n,dp);
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][1] = max(dp[i+1][1],-prices[i]+dp[i+1][0]);
            dp[i][0] = max(dp[i+1][0],prices[i]+dp[i+2][1]);
        }
        return dp[0][1];
    }
    
};