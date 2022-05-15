class Solution {
public:
    int minimumWhiteTiles(string s, int k, int len) {
        
        int n=s.length();
        
        vector<int>prefix(n+1,0);
        
        for(int i=1;i<=n;i++){
            
            prefix[i]=prefix[i-1]+(s[i-1]=='1' ? 1 : 0);
            
        }
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));
        
        for(int i=0;i<=k;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++){
            
            for(int j=0;j<=k;j++){
                
                int jump=(s[i-1]=='1' ? 1 : 0)+dp[i-1][j];
                
                dp[i][j]=jump;
                
                if(j!=0){
                    
                    int cover=(i-len>=0 ? dp[i-len][j-1] : 0);
                    
                    dp[i][j]=min(dp[i][j],cover);
                    
                }
                
            }
            
        }
        
        return dp[n][k];
        
    }
};