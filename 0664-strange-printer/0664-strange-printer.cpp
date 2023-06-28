class Solution {
public:
    
    int func(string &s,int i,int j,vector<vector<int>>&dp){
        
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1 + func(s,i+1,j,dp);
        
        for(int k=i+1;k<=j;k++){
            if(s[i] == s[k]){
                ans = min(ans, func(s,i+1,k,dp) + func(s,k+1,j,dp));
            }
        }
        
        return dp[i][j] = ans;
        
    }
    
    int strangePrinter(string s) {
        
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = func(s,0,n-1,dp);
        return ans;
        
    }
};