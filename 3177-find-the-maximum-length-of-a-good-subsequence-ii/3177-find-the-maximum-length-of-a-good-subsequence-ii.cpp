class Solution {
public:
    
 int maximumLength(vector<int>& nums, int k) {

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, int> mp1;

    for (int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        unordered_map<int, int> mp2 = mp1;
        for (int j = 0; j <= k; j++) {
            dp[i][j] = mp[nums[i]][j] + 1;
            if (j > 0) {
                dp[i][j] = max(dp[i][j], mp2[j - 1] + 1);
            }
            mp[nums[i]][j] = max(mp[nums[i]][j], dp[i][j]);
            mp1[j] = max(mp2[j], dp[i][j]);
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, dp[i][k]);
    }
    return maxLength;

 }
};