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
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;++i){
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;++i){
            dp[i][i+1]=(s[i]==s[i+1] ? 2 : 1);
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;++i){
                
                int j = i+L-1;
                
                if(s[i]==s[j]){
                    
                    dp[i][j] = 2 + dp[i+1][j-1];
                    
                }
                
                else{
                    
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
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