class Solution {
public:
    
    int MAX = INT_MAX;
    vector<vector<int>>dp;
    
    int func(vector<int>&nums,int i,int j){
        if(i > j) return 0;
        if(dp[i][j] != MAX) return dp[i][j];
        return dp[i][j] = max(nums[i] - func(nums,i+1,j), nums[j] - func(nums,i,j-1));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.clear();
        dp = vector<vector<int>>(n,vector<int>(n,MAX));
        int ans = func(nums,0,n-1);
        return ans >= 0;
    }
};