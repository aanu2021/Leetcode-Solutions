class Solution {
public:
    int stoneGameVII(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        vector<int>prefix(n+1,0);
        
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+arr[i];
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=max(arr[i],arr[i+1]);
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                int lsum=prefix[j]-prefix[i];
                int rsum=prefix[j+1]-prefix[i+1];
                
                dp[i][j]=max(lsum-dp[i][j-1],rsum-dp[i+1][j]);
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};