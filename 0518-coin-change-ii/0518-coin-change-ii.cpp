class Solution {
public:
    
    int dp[302][5002];
    
    int func(vector<int>&coins,int i,int amount,int n){
        
        if(amount==0){
            return 1;
        }
        
        if(i>=n){
            if(amount==0){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        
        int ans = 0;
        
        ans = func(coins,i+1,amount,n);
        
        if(coins[i]<=amount){
            
            ans += func(coins,i,amount-coins[i],n);
            
        }
        
        return dp[i][amount] = ans;
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = func(coins,0,amount,n);
        
        return ans;
        
    }
};