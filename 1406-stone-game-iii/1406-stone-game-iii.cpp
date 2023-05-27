class Solution {
public:
    
    /*
    
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
    
    */
    
    int func2(vector<int>&nums,int n){
        vector<int>dp(3,0);
        for(int i=n-1;i>=0;i--){
            int currmax = -1e9;
            int currSum = 0;
            currSum += nums[i];
            currmax = max(currmax,currSum - dp[0]);
            if(i + 1 < n){
                currSum += nums[i+1];
                currmax = max(currmax,currSum - dp[1]);
            }
            if(i + 2 < n){
                currSum += nums[i+2];
                currmax = max(currmax,currSum - dp[2]);
            }
            dp[2] = dp[1];
            dp[1] = dp[0];
            dp[0] = currmax;
        }
        return dp[0];
    }
    
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
        
        /*
        dp = vector<int>(n,-1);
        int maxDiff = func(nums,0,n);
        */
        
        int maxDiff = func2(nums,n);
        int currSum = accumulate(nums.begin(),nums.end(),0);
        int aliceSum = (currSum+maxDiff)/2;
        int bobSum = (currSum-maxDiff)/2;
        if(aliceSum > bobSum) return "Alice";
        else if(aliceSum < bobSum) return "Bob";
        else return "Tie";
    }
};
