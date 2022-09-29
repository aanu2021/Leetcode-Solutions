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
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;++i){
            dp[i][i]=0;
        }
        
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1]=0;
            }else{
                dp[i][i+1]=1;
            }
        }
        
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;++i){
                int j=i+L-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
        
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
