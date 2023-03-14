class Solution {
public:
    
    int func(vector<int>&arr,int i,int j,int n,vector<vector<int>>&dp){
        if(i > j) return 0;
        if(i == j) return (arr[i]*arr[i-1]*arr[i+1]);
        if(dp[i][j] != -1) return dp[i][j];
        int currMax = 0;
        for(int k=i;k<=j;k++){
            currMax = max(currMax,(arr[i-1]*arr[k]*arr[j+1]) + func(arr,i,k-1,n,dp) + func(arr,k+1,j,n,dp));
        }
        return dp[i][j] = currMax;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        arr.push_back(1);
        for(int &ele : nums) arr.push_back(ele);
        arr.push_back(1);
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        
        /*
        
        for(int i=1;i<=n;i++){
            dp[i][i] = (arr[i-1]*arr[i]*arr[i+1]);
        }
        for(int L=2;L<=n;L++){
            for(int i=1;i<=n-L+1;i++){
                int j = i+L-1;
                for(int k=i;k<=j;k++){
                    dp[i][j] = max(dp[i][j], (arr[i-1]*arr[k]*arr[j+1]) + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
        
        */
        
        int ans = func(arr,1,n,n,dp);
        return ans;
    }
};