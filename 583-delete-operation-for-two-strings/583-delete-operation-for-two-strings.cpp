class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
      
        
        return (m+n-(2*dp[m][n]));
        
    }
};