class Solution {
public:
    
    int dp[1002][102][2];
    
    int func(vector<int>&prices,int i,int n,int k,bool bought){
        
        if(k<0){
            return -1e9;
        }
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i][k][bought]!=-1){
            
            return dp[i][k][bought];
            
        }
        
        
        int ans=func(prices,i+1,n,k,bought);
        
        if(bought==true){
            
            ans=max(ans,-prices[i] + func(prices,i+1,n,k,false));
            
        }
        
        else if(bought==false && k>0){
            
            ans=max(ans,prices[i] + func(prices,i+1,n,k-1,true));
            
        }
        
        return dp[i][k][bought] = ans;
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        
        if(n==0 || k==0){
            return 0;
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
        
        int ans=func(prices,0,n,k,true);
        
        return ans;
        
    }
};