class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        s = "#" + s;
        p = "#" + p;
        
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        vector<bool>prev(n+1, false);
        vector<bool>curr(n+1, false);
        dp[0][0] = true;
        prev[0] = true;
        
        for(int i=1;i<=n;i++){
            if(p[i] == '*'){
                dp[0][i] = dp[0][i-2];
                prev[i] = prev[i-2];
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i] == p[j] || p[j] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                    curr[j] = prev[j-1];
                }
                else if(p[j] == '*'){
                    dp[i][j] = dp[i][j-2];
                    curr[j] = curr[j-2];
                    if(p[j-1] == '.' || s[i] == p[j-1]){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                        curr[j] = curr[j] || prev[j];
                    }
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
                curr[j] = false;
            }
        }
        
        return prev[n];
    }
};