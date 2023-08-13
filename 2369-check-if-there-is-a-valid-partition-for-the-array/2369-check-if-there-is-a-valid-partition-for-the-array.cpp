class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n+1,false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            if(i+1<n && nums[i+1]==nums[i]){
                dp[i] = dp[i] || dp[i+2];
            }
            if(i+2<n && nums[i+1]==nums[i] && nums[i+2]==nums[i+1]){
                dp[i] = dp[i] || dp[i+3];
            }
            if(i+2<n && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i+1]+1){
                dp[i] = dp[i] || dp[i+3];
            }
        }
        return dp[0];
    }
};