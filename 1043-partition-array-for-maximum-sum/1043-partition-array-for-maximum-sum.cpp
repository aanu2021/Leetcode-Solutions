class Solution {
public:
    
    int func(vector<int>& arr, int i, int n, int k, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxSum = 0;
        int currMax = arr[i];
        for(int j=i;j<min(n,i+k);j++){
            currMax = max(currMax, arr[j]);
            maxSum = max(maxSum, (currMax*(j-i+1)) + func(arr, j+1, n, k, dp));
        }
        return dp[i] = maxSum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n, -1);
        int ans = func(arr,0,n,k,dp);
        return ans;
    }
};