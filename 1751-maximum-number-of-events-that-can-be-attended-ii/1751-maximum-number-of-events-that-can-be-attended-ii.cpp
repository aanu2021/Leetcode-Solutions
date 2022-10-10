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
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=1;j<=k;j++){
                
                dp[i][j] = dp[i+1][j];
                
                vector<int>temp = {events[i][1],INT_MAX,INT_MAX};
                
                int idx = upper_bound(events.begin(),events.end(),temp)-events.begin();
                
                dp[i][j] = max(dp[i][j] , events[i][2] + dp[idx][j-1]);
                
            }
            
        }
        
        
        
        return dp[0][k];
        
    }
};