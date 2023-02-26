class Solution {
public:
    
    int func(string &s1,string &s2,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m && j == n) return 0;
        if(i == m) return (n-j);
        if(j == n) return (m-i);
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]){
            return dp[i][j] = func(s1,s2,i+1,j+1,m,n,dp);
        }
        else{
            int insOps = func(s1,s2,i,j+1,m,n,dp);
            int delOps = func(s1,s2,i+1,j,m,n,dp);
            int repOps = func(s1,s2,i+1,j+1,m,n,dp);
            return dp[i][j] = 1 + min({insOps,delOps,repOps});
        }
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = func(s1,s2,0,0,m,n,dp);
        return ans;
    }
};