class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.length();
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            for(int j=1;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        return curr[n];
    }
};

  // dp[i][j] = dp[i-1][j-1] + 1
  // dp[i][j] = max(dp[i-1][j],dp[i][j-1])  