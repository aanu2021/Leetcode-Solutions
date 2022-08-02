class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int>dp(n+2,n+2);
        
        dp[0]=0;
        
        for(int i=0;i<=n;++i){
            
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            
            for(int j=left+1;j<=right;++j){
                
                dp[j]=min(dp[j],dp[left]+1);
                
            }
            
        }
        
        if(dp[n]>n+1){
            return -1;
        }else{
            return dp[n];
        }
        
    }
};