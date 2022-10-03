class Solution {
public:
    
    int func(int i,int n,int mask,vector<int>&dp){
        
        if(i>n){
            return 1;
        }
        
        if(dp[mask]!=-1){
            return dp[mask];
        }
        
        int ans = 0;
        
        for(int j=1;j<=n;j++){
            if((mask&(1<<j)) && (j%i==0 || i%j==0)){
                ans += func(i+1,n,(mask^(1<<j)),dp);
            }
        }
        
        return dp[mask] = ans;
        
    }
    
    int countArrangement(int n) {
        
        int mask = (1<<(n+1));
        
        vector<int>dp(mask,-1);
        
        return func(1,n,mask-1,dp);
        
    }
};