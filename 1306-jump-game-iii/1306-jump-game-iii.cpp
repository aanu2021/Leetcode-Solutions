class Solution {
public:
    
    int func(vector<int>&arr,int i,int n,vector<int>&dp){
        if(i>=n || i<0) return 0;
        if(arr[i]==0) return 1;
        if(dp[i]!=-1) return dp[i];
        dp[i] = 0;
        return dp[i] = max(func(arr,i-arr[i],n,dp) , func(arr,i+arr[i],n,dp));
    }
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>dp(n,-1);
        int ans = func(arr,start,n,dp);
        return ans;
    }
};