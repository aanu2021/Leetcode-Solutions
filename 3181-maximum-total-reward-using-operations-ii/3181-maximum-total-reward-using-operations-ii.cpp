class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int M = *max_element(nums.begin(),nums.end());
        vector<int>dp(2*M + 5, 0);
        for(int i=0;i<n;i++){
            if(i == 0 || nums[i] != nums[i-1]){
                int lim = min(nums[i], nums.back() - nums[i]);
                for(int j=0;j<lim;j++){
                    dp[nums[i] + dp[j]] = nums[i] + dp[j];
                }
            }
        }
        return nums.back() + *max_element(dp.begin(),dp.begin() + nums.back());
    }
};