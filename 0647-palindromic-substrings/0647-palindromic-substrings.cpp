class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = (s[i]==s[i+1]);
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i + L - 1;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        int answer = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]) answer++;
            }
        }
        return answer;
    }
};