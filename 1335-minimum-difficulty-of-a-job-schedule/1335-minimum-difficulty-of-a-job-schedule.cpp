class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(vector<int>&nums,int i,int d,int n){
        if(d < 0) return 100000000;
        if(i == n){
            if(d == 0) return 0;
            else return 100000000;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int mini = 100000000;
        int maxi = nums[i];
        for(int j=i;j<n;j++){
            maxi = max(maxi, nums[j]);
            mini = min(mini, maxi + func(nums,j+1,d-1,n));
        }
        return dp[i][d] = mini;
    }
    
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();
        if(n < d) return -1;
        dp.clear();
        dp = vector<vector<int>>(n,vector<int>(d+1,-1));
        int ans = func(nums,0,d,n);
        return ans;
    }
};