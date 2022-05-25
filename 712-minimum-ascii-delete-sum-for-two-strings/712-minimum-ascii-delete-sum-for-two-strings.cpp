class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        s1="*"+s1;
        s2="*"+s2;
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1]+(int)s2[i];
        }
        
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+(int)s1[i];
        }
        
        for(int i=1;i<=m;i++){
            
            for(int j=1;j<=n;j++){
                
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1];
                }
                
                else{
                    
                    dp[i][j]=min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j]);
                    
                }
                
            }
            
        }
        
        return dp[m][n];
        
    }
};