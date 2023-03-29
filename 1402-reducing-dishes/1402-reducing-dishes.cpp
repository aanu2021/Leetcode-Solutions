const int MIN = -1000000000;

class Solution {
public:
    
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,MIN));
        
        for(int i=0;i<n;i++) dp[i][0] = 0;
        dp[0][1] = nums[0];
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = max(dp[i-1][j],(j*nums[i]) + dp[i-1][j-1]);
            }
        }

        int ans = 0;
        for(int i=0;i<=n;i++){
            ans = max(ans,dp[n-1][i]);
        }
        return ans;
    }
};

// -9 -8 0 1 5
 
    // dp[idx][turn] = dp[idx-1][turn] , (turn*nums[idx]) + dp[idx-1][turn-1]
    
    

