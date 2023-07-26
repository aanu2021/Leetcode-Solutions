class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int numWays(vector<string>& words, string target) {
        
        int m = words[0].length();
        int n = target.length();
        
        vector<vector<int>>freq(m,vector<int>(26,0));
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].length();j++){
                freq[j][words[i][j]-'a']++;
            }
        }
        
        for(int i=0;i<=m;i++){
            dp[n][i] = 1;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ll ways = dp[i][j+1];
                ways += (ll)dp[i+1][j+1]*(ll)(freq[j][target[i]-'a']);
                ways %= M;
                dp[i][j] = (int)ways;
            }
        }
        
        return dp[0][0];
    }
};