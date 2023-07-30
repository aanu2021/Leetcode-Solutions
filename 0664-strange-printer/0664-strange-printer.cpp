class Solution {
public:
    vector<vector<int>>dp;
    int func(string &s,int l,int r){
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 1 + func(s,l+1,r);
        for(int k=l+1;k<=r;k++){
            if(s[l] == s[k]){
                ans = min(ans,func(s,l+1,k) + func(s,k+1,r));
            }
        }
        return dp[l][r] = ans;
    }
    int strangePrinter(string s) {
        int n = s.length();
        dp.clear();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        int ans = func(s,0,n-1);
        return ans;
    }
};