class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string>S;
        for(string &str : wordDict){
            S.insert(str);
        }
        vector<bool>dp(n+1,false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            string str = "";
            for(int j=i;j<n;j++){
                str += s[j];
                if(S.find(str) != S.end()){
                    dp[i] = dp[i] || dp[j+1];
                    if(dp[i]){
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};