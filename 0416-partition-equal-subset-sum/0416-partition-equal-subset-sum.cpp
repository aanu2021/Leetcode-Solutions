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
    
    bool canPartition2(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = (sum/2);
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return func(nums,0,target,n,dp);
    }
    
    bool canPartition3(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = (sum/2);
        vector<vector<int>>dp(n,vector<int>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=target){
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=nums[i]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        int target = (sum/2);
        vector<bool>dp(target+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
    
};