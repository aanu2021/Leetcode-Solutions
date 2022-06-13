class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
        vector<int>dp(n,1e9);
        
        dp[0]=triangle[0][0];
        
        for(int i=1;i<n;++i){
            
            for(int j=i;j>=0;--j){
                
                dp[j]=dp[j]+triangle[i][j];
                
                if(j-1>=0){
                    dp[j]=min(dp[j],dp[j-1]+triangle[i][j]);
                }
                
            }
            
            
        }
        
       
        int ans=1e9;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
        
        return ans;
        
    }
};