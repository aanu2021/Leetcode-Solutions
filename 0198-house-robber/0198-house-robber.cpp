class Solution {
public:
    
    int func(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = func(nums,i+1,n,dp);
        ans = max(ans,nums[i]+func(nums,i+2,n,dp));
        return dp[i] = ans;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = func(nums,0,n,dp);
        return ans;
    }
};