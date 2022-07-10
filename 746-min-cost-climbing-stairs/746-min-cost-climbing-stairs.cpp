class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
         cost.push_back(0);
        
        int n=cost.size();
        
        vector<int>dp(n,0);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            
            dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
            
        }
        
        return dp[n-1];
        
    }
};