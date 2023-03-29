const int MAX = INT_MAX;

class Solution {
public:
    
    int func(vector<int>&nums,int idx,int turn,int n,vector<vector<int>>&dp){
        if(idx == n) return 0;
        if(dp[idx][turn] != MAX) return dp[idx][turn];
        int currValue = func(nums,idx+1,turn,n,dp);
        currValue = max(currValue,(nums[idx]*(turn+1)) + func(nums,idx+1,turn+1,n,dp));
        return dp[idx][turn] = currValue;
    }
    
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n,vector<int>(n,MAX));
        int ans = func(nums,0,0,n,dp);
        return ans;
    }
};


