class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[n-1] = nums[n-1];
        deque<int>q;
        q.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while(!q.empty() && q.front() > i+k){
                q.pop_front();
            }
            dp[i] = nums[i] + dp[q.front()];
            while(!q.empty() && dp[q.back()] < dp[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[0];
    }
};
   
    