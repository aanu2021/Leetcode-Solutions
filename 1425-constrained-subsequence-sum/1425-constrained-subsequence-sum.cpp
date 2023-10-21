class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        int maxval = INT_MIN;
        for(int i=0;i<n;i++) dp[i] = nums[i];
        deque<int>q;
        for(int i=0;i<n;i++){
            while(!q.empty() && q.front() < i-k) q.pop_front();
            if(!q.empty()) dp[i] = nums[i] + max(dp[q.front()], 0);
            maxval = max(maxval, dp[i]);
            while(!q.empty() && dp[q.back()] < dp[i]) q.pop_back();
            q.push_back(i);
        }
        return maxval;
    }
};