class Solution {
public:
    
    int func(vector<int>&nums,int i,int j,vector<int>&prefix,vector<vector<int>>&dp){
        
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = max(prefix[j+1]-prefix[i+1]-func(nums,i+1,j,prefix,dp) , prefix[j]-prefix[i]-func(nums,i,j-1,prefix,dp));
        
    }
    
    int stoneGameVII(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = func(nums,0,n-1,prefix,dp);
        return ans;
    }
};