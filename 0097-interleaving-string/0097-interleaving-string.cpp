class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.length();
        int n = s2.length();
        int len = s3.length();
        
        if((m+n) != len) return false;
        
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        vector<int>prev(n+1,false);
        
        dp[0][0] = true;
        prev[0] = true;
        
        for(int i=1;i<=n;i++){
            if(s2[i-1]==s3[i-1]){
                prev[i] = prev[i-1];
            }
        }
        
        for(int i=1;i<=n;i++){
            if(s2[i-1]==s3[i-1]){
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i=1;i<=m;i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for(int i=1;i<=m;i++){
            vector<int>curr(n+1,false);
            if(prev[0] && (s1[i-1]==s3[i-1])){
                curr[0] = true;
            }
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s3[i+j-1]){
                    curr[j] = prev[j];
                }
                if(s2[j-1]==s3[i+j-1]){
                    curr[j] = curr[j] || curr[j-1];
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s3[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                if(s2[j-1] == s3[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        
        return prev[n];
        
    }
};