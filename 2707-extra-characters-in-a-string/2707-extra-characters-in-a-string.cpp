class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>S;
        for(string &str : dictionary){
            S.insert(str);
        }
        int n = s.length();
        vector<int>dp(n+1,n);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            string str = "";
            dp[i] = 1 + dp[i+1];
            for(int j=i;j<n;j++){
                str += s[j];
                if(S.find(str) != S.end()){
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};