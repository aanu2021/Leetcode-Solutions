class Solution {
public:
    
    int maxTotalReward(vector<int>& rewards) {
        sort(begin(rewards), end(rewards));
        int dp[50000] = {}, sz = rewards.size();
        for (int i = 0; i < sz; ++i)
            if (i == 0 || rewards[i - 1] != rewards[i]) {
                int lim = min(rewards[i], rewards.back() - rewards[i]);
                for (int x = 0; x < lim; ++x)
                    dp[rewards[i] + dp[x]] = rewards[i] + dp[x];
            }
        return rewards.back() + *max_element(begin(dp), begin(dp) + rewards.back());
    }
    
};

    
    