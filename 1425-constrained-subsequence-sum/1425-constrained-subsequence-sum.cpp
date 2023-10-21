class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxval = INT_MIN;
        for(int i=0;i<n;i++) maxval = max(maxval, nums[i]);
        vector<int>dp(n,0);
        deque<int>q;
        for(int i=0;i<n;i++){
            while(!q.empty() && q.front() < i-k){
                q.pop_front();
            }
            dp[i] = nums[i];
            if(!q.empty()){
                dp[i] = nums[i] + max(dp[q.front()], 0);
            }
            while(!q.empty() && dp[q.back()] < dp[i]){
                q.pop_back();
            }
            q.push_back(i);
            maxval = max(maxval, dp[i]);
        }
        return maxval;
    }
};

