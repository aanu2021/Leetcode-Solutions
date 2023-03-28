class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector<int>dp(n+1,0);
        int j = 0;
        int m = days.size();
        for(int i=1;i<=n;i++){
            if(i==days[j]){
                int c1 = dp[i-1];
                int c7 = (i-7 >= 0 ? dp[i-7] : 0);
                int c30 = (i-30 >= 0 ? dp[i-30] : 0);
                dp[i] = min({c1+costs[0],c7+costs[1],c30+costs[2]});
                j++;
            }
            else{
                dp[i] = dp[i-1];
                continue;
            }
        }
        return dp[n];
    }
};