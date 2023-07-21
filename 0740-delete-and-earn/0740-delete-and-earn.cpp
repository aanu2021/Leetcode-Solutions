class Solution {
public:
    
    vector<int>dp;
    
    int func(vector<int>&nums,int i,int n){
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int answer = 0;
        int currOcc = 0;
        int j = i;
        while(j<n && nums[j]==nums[i]){
            currOcc++;
            j++;
        }
        // skip it
        answer = max(answer, func(nums,j,n));
        // pick it
        while(j<n && nums[j]==nums[i] + 1){
            j++;
        }
        answer = max(answer, (currOcc*nums[i]) + func(nums,j,n));
        return dp[i] = answer;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        dp.clear();
        dp = vector<int>(n,-1);
        int ans = func(nums,0,n);
        return ans;
    }
};