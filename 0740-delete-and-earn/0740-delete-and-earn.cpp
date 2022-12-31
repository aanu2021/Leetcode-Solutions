class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>dp(maxi+1,0);
        vector<int>occ(maxi+1,0);
        for(int ele:nums){
            occ[ele]++;
        }
        dp[0] = 0;
        dp[1] = occ[1];
        for(int i=2;i<=maxi;i++){
            dp[i] = max(dp[i-1],dp[i-2] + (occ[i]*i));
        }
        return dp[maxi];
    }
};