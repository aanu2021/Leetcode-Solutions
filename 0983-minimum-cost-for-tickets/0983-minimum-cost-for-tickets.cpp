class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,0);
        dp[n-1] = min({costs[0],costs[1],costs[2]});
        for(int i=n-2;i>=0;i--){
            int c1 = costs[0];
            int c7 = costs[1];
            int c30 = costs[2];
            int j = lower_bound(days.begin(),days.end(),days[i] + 1) - days.begin();
            if(j < n) c1 += dp[j];
            j = lower_bound(days.begin(),days.end(),days[i] + 7) - days.begin();
            if(j < n) c7 += dp[j];
            j = lower_bound(days.begin(),days.end(),days[i] + 30) - days.begin();
            if(j < n) c30 += dp[j];
            dp[i] = min({c1,c7,c30});
        }
        return dp[0];
    }
};