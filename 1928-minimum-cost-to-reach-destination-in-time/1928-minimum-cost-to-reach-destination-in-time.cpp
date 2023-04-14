class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>>dp(n,vector<int>(maxTime+1,1e9));
        dp[0][0] = passingFees[0];
        int ans = 1e9;
        for(int i=1;i<=maxTime;i++){
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int timer = edges[j][2];
                if(i >= timer){
                    dp[v][i] = min(dp[v][i],dp[u][i-timer] + passingFees[v]);
                    dp[u][i] = min(dp[u][i],dp[v][i-timer] + passingFees[u]);
                }
            }
            ans = min(ans,dp[n-1][i]);
        }
        return ans >= 1e9 ? -1 : ans;
    }
};

