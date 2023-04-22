class Solution {
public:
    
    int dp[501][501];
    
    int func(string &s,int l,int r){
        if(l > r) return 0;
        if(l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r] = func(s,l+1,r-1);
        }
        else{
            return dp[l][r] = 1 + min(func(s,l+1,r),func(s,l,r-1));
        }
    }
    
    int minInsertions(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        int ans = func(s,0,n-1);
        return ans;
    }
};