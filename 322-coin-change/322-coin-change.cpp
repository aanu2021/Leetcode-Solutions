class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        
        vector<int>dp(amt+1,1e9);
        
        dp[0]=0;
        
        int n=coins.size();
        
        for(int i=0;i<n;i++){
            
            for(int j=coins[i];j<=amt;j++){
                
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
                
            }
            
        }
        
    if(dp[amt]>=1e9){
        
        return -1;
        
    }
        
        else{
            
            return dp[amt];
            
         }
            
        }
};