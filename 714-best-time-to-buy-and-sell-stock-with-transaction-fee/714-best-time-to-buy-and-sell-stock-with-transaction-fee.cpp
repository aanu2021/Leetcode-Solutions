class Solution {
public:
    
    int dp[50005][2];
    
    int func(vector<int>&prices,int i,int n,int fee,bool bought){
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][bought]!=-1){
            return dp[i][bought];
        }
        
        int ans=func(prices,i+1,n,fee,bought);
        
        if(bought){
            
            ans=max(ans,-prices[i] + func(prices,i+1,n,fee,false));
            
        }
        
        else{
            
            ans=max(ans,prices[i]-fee+func(prices,i+1,n,fee,true));
            
        }
        
        return dp[i][bought]=ans;
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
        
        int ans=func(prices,0,n,fee,true);
        
        return ans;
        
    }
};