class Solution {
public:
    
    int func(vector<vector<int>>&events,int idx,int n,int k,vector<vector<int>>&dp){
        
        if(idx>=n){
            return 0;
        }
        
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        
        int currval = func(events,idx+1,n,k,dp);
        
        if(k>0){
            
            vector<int>temp = {events[idx][1],INT_MAX,INT_MAX};
            
            int j = upper_bound(events.begin(),events.end(),temp)-events.begin();
            
            currval = max(currval , events[idx][2] + func(events,j,n,k-1,dp));
            
        }
        
        return dp[idx][k] = currval;
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(),events.end());
        
        int n = events.size();
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        
        int ans = func(events,0,n,k,dp);
        
        return ans;
        
    }
};