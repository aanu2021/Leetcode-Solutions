class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int K) {
        
        int n=piles.size();
        
        vector<vector<int>>dp(n+1,vector<int>(K+1,0));
        
        for(int i=1;i<=n;i++){
            
            for(int k=1;k<=K;k++){
                
                dp[i][k]=dp[i-1][k];
                
                int picked=1;
                
                int sum=0;
                
                for(int v:piles[i-1]){
                    
                    if(k-picked<0){
                        break;
                    }
                    
                    sum+=v;
                    
                    dp[i][k]=max(dp[i][k],dp[i-1][k-picked]+sum);
                    
                    picked++;
                    
                }
                
            }
            
        }
        
        return dp[n][K];
        
    }
};