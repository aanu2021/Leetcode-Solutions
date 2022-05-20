class Solution {
public:
    int numDistinct(string s, string t) {
        
        int m=s.length();
        int n=t.length();
        
        vector<vector<unsigned int>>dp(m+1,vector<unsigned int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            dp[0][i]=0;
        }
        
        for(int i=0;i<=m;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
                
            }
            
        }
        
        return dp[m][n];
        
    }
};