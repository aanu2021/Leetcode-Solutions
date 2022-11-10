class Solution {
public:
    
    int func(vector<int>&nums,int i,int target,int n,vector<vector<int>>&dp){
        
        if(target==0) return 1;
        if(i==n) return 0;
        if(dp[i][target]!=-1) return dp[i][target];

        
        int ans = func(nums,i+1,target,n,dp);
        if(target>=nums[i]){
            ans = max(ans,func(nums,i+1,target-nums[i],n,dp));
        }
        
        return dp[i][target] = ans;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = (sum/2);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(nums,0,target,n,dp);
    }
};