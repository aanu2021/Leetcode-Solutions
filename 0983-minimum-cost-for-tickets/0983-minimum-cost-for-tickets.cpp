class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector<int>dp(n+1,0);
        int j = 0;
        for(int i=1;i<=n;i++){
            if(i == days[j]){
                int cost1 = costs[0];
                int cost2 = costs[1];
                int cost3 = costs[2];
                if(i-1 >= 0) cost1 += dp[i-1];
                if(i-7 >= 0) cost2 += dp[i-7];
                if(i-30 >= 0) cost3 += dp[i-30];
                dp[i] = min({cost1,cost2,cost3});
                j++;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
};