class Solution {
public:
    int numSquares(int n) {
        
        if(n<=3){
           return n;
        }
        
        vector<int>dp(n+1);
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++){
            
            dp[i]=1e9;
            
            for(int j=1;j*j<=i;j++){
                
                int rem=(i-(j*j));
                
                dp[i]=min(dp[i],dp[rem]+1);
                
            }
            
        }
        
        return dp[n];
        
    }
};