class Solution {
public:
    
    int func(vector<int>&arr,int i,int j,vector<vector<int>>&dp)
    {
        
        if(i>j){
            return 0;
        }
        
        if(i==j){
            return dp[i][j] = (arr[i-1]*arr[i]*arr[i+1]);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        dp[i][j] = 0;
        
        for(int k=i;k<=j;k++){
            
            dp[i][j] = max(dp[i][j],func(arr,i,k-1,dp) + func(arr,k+1,j,dp) + (arr[i-1]*arr[k]*arr[j+1]));
            
        }
        
        return dp[i][j];
        
    }    
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>arr;
        
        arr.push_back(1);
        
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        
        arr.push_back(1);
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        
        int ans = func(arr,1,n,dp);
        
        return ans;
        
    }
};