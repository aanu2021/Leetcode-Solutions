class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int>dp(n+2,-1);
        
        for(int i=0;i<ranges.size();++i){
            
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            
            dp[left]=max(dp[left],right);
            
        }
        
        int currmax=dp[0];
        int nextmax=-1;
        
        int jumps=1;
        
        for(int i=0;i<=n;++i){
            
            nextmax=max(nextmax,dp[i]);
            
            if(i==currmax){
                currmax=nextmax;
                jumps++;
            }
            
            if(currmax==n){
                return jumps;
            }
            
        }
        
        return -1;
        
    }
};