class Solution {
public:
    
    int dp[20][10002];
    
    int func(vector<int>&coins,int i,int amount,int n){
        
        if(i>=n){
            if(amount==0){
                return 0;
            }else{
                return 1e9;
            }
        }
        
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        
        int ans = 1e9;
        
        ans = func(coins,i+1,amount,n);
        
        if(coins[i]<=amount){
            
            ans = min(ans,1 + func(coins,i,amount-coins[i],n));
            
        }
        
        return dp[i][amount] = ans;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = func(coins,0,amount,n);
        
        if(ans>=1e9) return -1;
        
        return ans;
        
//         vector<int>dp(amount+1,1e9);
        
//         dp[0] = 0;
        
//         for(int i=0;i<n;i++){
            
//             for(int j=coins[i];j<=amount;j++){
                
//                 dp[j] = min(dp[j],1 + dp[j-coins[i]]);
                
//             }
            
//         }
        
//         if(dp[amount]>=1e9) return -1;
        
//         return dp[amount];
        
    }
};