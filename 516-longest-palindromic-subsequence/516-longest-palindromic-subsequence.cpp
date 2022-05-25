class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n=s.length();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=2;
            }else{
                dp[i][i+1]=1;
            }
        }
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};