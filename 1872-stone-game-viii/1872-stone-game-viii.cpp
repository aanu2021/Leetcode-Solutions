class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        vector<int>dp(n);
        
        dp[n-2] = prefix[n-1];
        
        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+1],prefix[i+1]-dp[i+1]);
        }
        
        return dp[0];
        
    }
};
  
       
    