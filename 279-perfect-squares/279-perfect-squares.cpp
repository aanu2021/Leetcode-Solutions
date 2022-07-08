class Solution {
public:
    int numSquares(int n) {
        
        vector<int>v;
        
        int i=1;
        
        while(i*i<=n){
            v.push_back(i*i);
            i++;
        }
        
        int sz=v.size();
        
        vector<int>dp(n+1,1e9);
        
        dp[0]=0;
        
        for(int i=0;i<sz;i++){
            
            for(int j=v[i];j<=n;j++){
                
                dp[j]=min(dp[j],dp[j-v[i]]+1);
                
            }
            
        }
        
        return dp[n];
        
    }
};