class Solution {
public:
    
    int dp[100002][3][2];
    
    int func(vector<int>&prices,int i,int k,int bought){
        
        if(i==prices.size()) return 0;
        if(dp[i][k][bought]!=-1) return dp[i][k][bought];
        int ans = 0;
        ans = func(prices,i+1,k,bought);
        if(bought){
            ans=max(ans,-prices[i]+func(prices,i+1,k,0));
        }else{
            if(k>0){
                ans=max(ans,prices[i]+func(prices,i+1,k-1,1));
            }
        }
        return dp[i][k][bought] = ans;
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i=0;i<=n;i++){
            for(int j=2;j>=0;j--){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        int ans = func(prices,0,2,1);
        return ans;
    }
};