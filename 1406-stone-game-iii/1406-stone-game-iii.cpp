class Solution {
public:
    
    vector<int>dp;
    
    int func(vector<int>&nums,int i,int n){
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = -1e9;
        int currSum = 0;
        for(int j=i;j<=min(i+2,n-1);j++){
            currSum += nums[j];
            ans = max(ans,currSum - func(nums,j+1,n));
        }
        return dp[i] = ans;
    }
    
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n,-1);
        int maxDiff = func(nums,0,n);
        int currSum = accumulate(nums.begin(),nums.end(),0);
        int aliceSum = (currSum+maxDiff)/2;
        int bobSum = (currSum-maxDiff)/2;
        if(aliceSum > bobSum) return "Alice";
        else if(aliceSum < bobSum) return "Bob";
        else return "Tie";
    }
};