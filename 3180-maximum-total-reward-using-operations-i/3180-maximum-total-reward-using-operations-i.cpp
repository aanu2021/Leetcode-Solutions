class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<int>&nums, int i, int psum, int n, int MAX){
        if(i == n) return 0;
        if(dp[i][psum] != -1) return dp[i][psum];
        int answer = func(nums, i+1, psum, n, MAX);
        if(nums[i] > psum){
            int nextSum = min(MAX, nums[i] + psum);
            answer = max(answer, nums[i] + func(nums, i+1, nextSum, n, MAX));
        }
        return dp[i][psum] = answer;
    }
    
    int maxTotalReward(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int M = *max_element(nums.begin(),nums.end());
        dp.clear();
        dp = vector<vector<int>>(n, vector<int>(M+5, -1));
        int ans = func(nums, 0, 0, n, M+1);
        return ans;
    }
};

    
    