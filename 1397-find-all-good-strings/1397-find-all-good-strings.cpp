class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[501][51][2][2];
    
    vector<int>computeLPS(string &str){
        int n = str.length();
        vector<int>lps(n, 0);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            while(len > 0 && str[len] != str[i]){
                len = lps[len-1];
            }
            if(str[len] == str[i]) len++;
            lps[i] = len;
        }
        return lps;
    }
    
    int func(int i, int evilMatched, bool leftBound, bool rightBound, string &s1, string &s2, string &evil, vector<int>&lps){
        
        if(evilMatched == evil.length()) return 0;
        if(i == s1.length()) return 1;
        if(dp[i][evilMatched][leftBound][rightBound] != -1) return dp[i][evilMatched][leftBound][rightBound];
        
        ll ways = 0LL;
        char from = (leftBound ? s1[i] : 'a');
        char to = (rightBound ? s2[i] : 'z');
        
        for(char ch=from;ch<=to;ch++){
            int j = evilMatched;
            while(j > 0 && ch != evil[j]) j = lps[j-1];
            if(evil[j] == ch) j++;
            ways += (ll)func(i+1, j, (leftBound & (ch == from)), (rightBound & (ch == to)), s1, s2, evil, lps);
            ways %= M;
        }
        
        return dp[i][evilMatched][leftBound][rightBound] = (int)ways;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int>lps = computeLPS(evil);
        memset(dp, -1, sizeof(dp));
        return func(0, 0, true, true, s1, s2, evil, lps);
    }
};