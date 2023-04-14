class Solution {
public:
    
    int func(string &s,int l,int r,vector<vector<int>>&dp){
        if(l > r) return 0;
        if(l==r) return 1;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r] = 2 + func(s,l+1,r-1,dp);
        }else{
            return dp[l][r] = max(func(s,l+1,r,dp),func(s,l,r-1,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = func(s,0,n-1,dp);
        return ans;
    }
};