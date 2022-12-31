class Solution {
public:
    
    int func(vector<int>&nums,int i,int n,vector<int>&dp){
        
        // Base Case
        
        if(i==n) return 0;
        
        // Memoization
        
        if(dp[i]!=-1) return dp[i];
        
        int score_skip = 0 , score_pick = 0;
        
        // Skip 
        
        int j = i;
        
        while(j<n && nums[j]==nums[i]){
            j++;
        }
        
        score_skip = func(nums,j,n,dp);
        
        // Pick
        
        score_pick += (nums[i]*(j-i));
        
        while(j<n && nums[j]==nums[i] + 1){
            j++;
        }
        
        score_pick += func(nums,j,n,dp);
        
        return dp[i] = max(score_skip,score_pick);
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        int ans = func(nums,0,n,dp);
        return ans;
    }
};