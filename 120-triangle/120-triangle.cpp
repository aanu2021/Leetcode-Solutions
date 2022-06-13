class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        
        dp[0][0]=triangle[0][0];
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<=i;j++){
                
                
                if(j-1>=0){
                    
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
                    
                }
                
                if(j<n){
                    
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+triangle[i][j]);
                    
                }
                
                
            }
            
        }
        
        int ans=1e9;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        
        return ans;
        
    }
};