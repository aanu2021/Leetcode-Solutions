class Solution {
public:
    
    vector<vector<int>>dp;
    
    int func(int i,int remain,vector<int>&cost,vector<int>&time,int n){
        if(remain <= 0) return 0;
        if(i==n) return 1e9;
        if(dp[i][remain] != -1) return dp[i][remain];
        int ans = cost[i] + func(i+1,remain-1-time[i],cost,time,n);
        ans = min(ans, func(i+1,remain,cost,time,n));
        return dp[i][remain] = ans;
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        dp = vector<vector<int>>(n,vector<int>(n+1,-1));
        int ans = func(0,n,cost,time,n);
        return ans;
    }
};