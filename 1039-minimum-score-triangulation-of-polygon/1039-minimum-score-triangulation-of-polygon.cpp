class Solution {
public:
    int minScoreTriangulation(vector<int>& arr) {
        
        int n=arr.size();
        
        if(n==3){
            return arr[0]*arr[1]*arr[2];
        }
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<=n-3;i++){
            dp[i][i+2]=(arr[i]*arr[i+1]*arr[i+2]);
        }
        
        for(int L=4;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                dp[i][j]=INT_MAX;
                
                for(int k=i+1;k<j;k++){
                    
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+(arr[i]*arr[k]*arr[j]));
                    
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};