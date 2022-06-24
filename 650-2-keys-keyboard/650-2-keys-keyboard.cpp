class Solution {
public:
    int minSteps(int n) {
        
        vector<int>dp(n+1,0);
        
        if(n==1){
            return 0;
        }
        
        dp[2]=2;
        
        dp[1]=0;
        
        for(int i=3;i<=n;i++){
            
            dp[i]=1e9;
            
            for(int j=1;j<=i;++j){
                
                if(i%j==0){
                    
                    dp[i]=min(dp[i],dp[j]+(i/j));
                    
                }
                
            }
            
        }
        
        return dp[n];
        
    }
};