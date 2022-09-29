class Solution {
public:
    
    int func(string &s,int i,int j,vector<vector<int>>&dp){
        
        if(i >= j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]) return dp[i][j] = func(s,i+1,j-1,dp);
        
        else  return dp[i][j] = 1 + min(func(s,i+1,j,dp),func(s,i,j-1,dp));
        
    }
    
    int minInsertions(string s) {
       
        int n=s.length();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        int ans = func(s,0,n-1,dp);
        
        return ans;
        
    }
};

/*

l e e t c o d e l
  i           j
  
  1 . if(s[i]==s[j])  i++; j--
  2 . else            1 + (s[i+1...j] , s[i...j-1]) 
      
      
  Recursion :-
      
      Base Case : i >= j  dp[i][j] = 0
          
      Transitions :    
      
      s[i] == s[j]  dp[i][j] = dp[i+1][j-1]
      
      s[i] != s[j]  dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j-1])
      
      */
