class Solution {
public:
    
    int func(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum = 0;
        int ans = -1e9;
        for(int j=i;j<min(i+3,n);j++){
            sum+=nums[j];
            ans = max(ans,sum - func(nums,j+1,n,dp));
        }
        return dp[i] = ans;
    }
    
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = func(nums,0,n,dp);
        if(ans>0){
            return "Alice";
        }else if(ans<0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};