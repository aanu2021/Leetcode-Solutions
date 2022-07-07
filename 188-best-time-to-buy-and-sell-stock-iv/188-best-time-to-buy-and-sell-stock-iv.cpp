class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        
        if(n<=1 || k==0){
            return 0;
        }
        
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        
        dp[0][0]=0;
        
        for(int i=1;i<=k;i++){
            
            vector<int>v=dp[i-1];
            
            vector<int>prefix(n,0);
            
            prefix[0]=v[0]-prices[0];
            
            for(int j=1;j<n;j++){
                
                prefix[j]=max(prefix[j-1],v[j]-prices[j]);
                
            }
            
            for(int j=1;j<n;j++){
                
                dp[i][j]=max(dp[i][j-1],prefix[j-1]+prices[j]);
                
            }
            
        }
        
        return dp[k][n-1];
        
    }
};