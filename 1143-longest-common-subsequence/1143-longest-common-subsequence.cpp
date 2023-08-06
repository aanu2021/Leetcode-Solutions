class Solution {
public:
    
    int func(string &s1,string &s2,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m || j==n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + func(s1,s2,i+1,j+1,m,n,dp);
        }
        else{
            return dp[i][j] = max(func(s1,s2,i+1,j,m,n,dp), func(s1,s2,i,j+1,m,n,dp));
        }
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = func(s1,s2,0,0,m,n,dp);
        return ans;
        // for(int i=m-1;i>=0;i--){
        //     for(int j=n-1;j>=0;j--){
        //         if(s1[i] == s2[j]){
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        // return dp[0][0];
    }
};

// 0 1 2 3 4
// a b c d e

// a c e
// 0 1 2
    
    
