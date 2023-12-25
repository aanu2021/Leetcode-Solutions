class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0') return 0;
        vector<int>dp(n+1,0);
        dp[0] = 1;
        s = "*" + s;
        for(int i=1;i<=n;i++){
            if(s[i] >= '1' && s[i] <= '9'){
                dp[i] += dp[i-1];
            }
            if(i-2 >= 0){
                if((s[i-1] == '1' && (s[i] >= '0' && s[i] <= '9')) || (s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6'))){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};