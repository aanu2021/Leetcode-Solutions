class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
        for(int i=1;i<=n;i++){
            dp[i][i] = (nums[i-1]*nums[i]*nums[i+1]);
        }
        for(int L=2;L<=n;L++){
            for(int i=1;i<=n-L+1;i++){
                int j = i+L-1;
                for(int k=i;k<=j;k++){
                    int currScore = nums[i-1]*nums[k]*nums[j+1];
                    currScore += dp[i][k-1];
                    currScore += dp[k+1][j];
                    dp[i][j] = max(dp[i][j], currScore);
                }
            }
        }
        return dp[1][n];
    }
};