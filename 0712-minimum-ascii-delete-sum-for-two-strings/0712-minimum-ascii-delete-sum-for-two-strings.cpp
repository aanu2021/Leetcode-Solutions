class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        s1 = "#" + s1;
        s2 = "#" + s2;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = (int)s1[i] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int totalSum = 0;
        for(int i=1;i<=m;i++){
            totalSum += (int)(s1[i]);
        }
        for(int j=1;j<=n;j++){
            totalSum += (int)(s2[j]);
        }
        
        totalSum -= (2*dp[m][n]);
        return totalSum;
        
    }
};