class Solution {
public:
    
    int func(string &s,int i,int j,vector<vector<int>>&dp){
        
        if(i > j) return 0;
        
        if(i == j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]){
            
            return dp[i][j] = 2 + func(s,i+1,j-1,dp);
            
        }
        
        else{
            
            return dp[i][j] = max(func(s,i+1,j,dp),func(s,i,j-1,dp));
            
        }
        
    }
    
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int ans = func(s,0,n-1,dp);
        
        return ans;
        
    }
};


/*

m c a d b x c

  i         j



dp[i][j] == Longest Palindromic Subsequence inside the substring             (si...sj)

i == j        -->  dp[i][j] = 1   
    
s[i] == s[j]  -->  dp[i][j] = 2 + dp[i+1][j-1]

s[i] != s[j]  -->  dp[i][j] = max(dp[i+1][j] , dp[i][j-1])
    
    
s0 s1 s2 s3 s4

s0 == s4  and  s1 == s3 and s2 == s2

s0 == s4  and  (s1 s2 s3) is also a Palindrome

s1 == s3  and  (s2) is also a Palindrome

m b a b m

*/