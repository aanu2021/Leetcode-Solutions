class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n==0 || s[0]=='0') return 0;
        vector<int>dp(n+1,0);
        dp[0] = 1;
        s = "*" + s;
        for(int i=1;i<=n;i++){
            char curr = s[i];
            char prev = s[i-1];
            if(curr>'0') dp[i]+=dp[i-1];
            if(prev=='1' || (prev=='2' && curr<='6')){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};