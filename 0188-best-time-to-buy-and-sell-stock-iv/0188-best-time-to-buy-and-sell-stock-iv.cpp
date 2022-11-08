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
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        int ans = func(prices,0,k,1,n,dp);
        return ans;
    }
};