class Solution {
public:
    
    /*
    
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
    
    */
    
    int minInsertions(string s) {
        int n = s.length();
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = (s[i] != s[i+1]);
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i + L - 1;
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};