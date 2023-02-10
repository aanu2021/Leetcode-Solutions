class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        arr.push_back(1);
        for(int ele : nums){
            arr.push_back(ele);
        }
        arr.push_back(1);
        vector<vector<int>>dp(n+5,vector<int>(n+5,0));
        for(int i=1;i<=n;i++){
            dp[i][i] = (arr[i]*arr[i-1]*arr[i+1]);
        }
        for(int L=2;L<=n;L++){
            for(int i=1;i<=n-L+1;i++){
                int j = i+L-1;
                for(int k=i;k<=j;k++){
                    dp[i][j] = max(dp[i][j],(arr[i-1]*arr[k]*arr[j+1]) + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};