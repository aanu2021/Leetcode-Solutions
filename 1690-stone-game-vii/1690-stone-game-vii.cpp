class Solution {
public:
    
    int stoneGameVII(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=max(nums[i],nums[i+1]);
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                dp[i][j] = max(prefix[j+1]-prefix[i+1]-dp[i+1][j] , prefix[j]-prefix[i]-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};