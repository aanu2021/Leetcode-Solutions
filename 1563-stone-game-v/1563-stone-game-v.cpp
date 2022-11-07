class Solution {
public:
    
    int func(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxval = 0;
        int rsum = 0;
        for(int idx=i;idx<=j;idx++){
            rsum += nums[idx];
        }
        int lsum = 0;
        for(int idx=i;idx<=j;idx++){
            lsum += nums[idx];
            rsum -= nums[idx];
            if(lsum > rsum){
                maxval = max(maxval,rsum + func(nums,idx+1,j,dp));
            }else if(lsum < rsum){
                maxval = max(maxval,lsum + func(nums,i,idx,dp));
            }else{
                maxval = max(maxval,max(lsum + func(nums,i,idx,dp),rsum + func(nums,idx+1,j,dp)));
            }
        }
        return dp[i][j] = maxval;
    }
    
    int stoneGameV(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = func(nums,0,n-1,dp);
        return ans;
    }
};