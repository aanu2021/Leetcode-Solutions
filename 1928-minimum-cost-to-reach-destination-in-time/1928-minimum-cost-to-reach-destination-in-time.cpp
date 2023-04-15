class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        int n = passingFees.size();
        int ans = 1e9;
        
        vector<vector<int>>dp(n,vector<int>(maxTime+1,1e9));
        dp[0][0] = passingFees[0];
        
        for(int i=1;i<=maxTime;i++){
            for(int j=0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int tim = edges[j][2];
                if(i >= tim){
                    dp[u][i] = min(dp[u][i],dp[v][i-tim]+passingFees[u]);
                    dp[v][i] = min(dp[v][i],dp[u][i-tim]+passingFees[v]);
                }
            }
            ans = min(ans,dp[n-1][i]);
        }
        
        if(ans >= 1e9) return -1;
        else return ans;
        
    }
};