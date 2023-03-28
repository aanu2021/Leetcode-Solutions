class Solution {
public:
    
    vector<int>duration;
    
    int func(vector<int>&days,int i,int n,vector<int>&costs,vector<int>&dp){
        
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        int j = i;
        for(int k=0;k<3;k++){
            while(j < n && days[j] < days[i] + duration[k]) j++;
            ans = min(ans,costs[k] + func(days,j,n,costs,dp));
        }
        return dp[i] = ans;
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        duration.push_back(1);
        duration.push_back(7);
        duration.push_back(30);
        vector<int>dp(n,-1);
        int ans = func(days,0,n,costs,dp);
        return ans;
        
    }
};

