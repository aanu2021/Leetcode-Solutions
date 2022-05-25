class Solution {
public:
    int minInsertions(string s) {
        
        int n=s.length();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        
        if(n==1){
            return 0;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=0;
            }else{
                dp[i][i+1]=1;
            }
        }
        
        
        for(int L=3;L<=n;L++){
            
            for(int i=0;i<n-L+1;i++){
                
                int j=i+L-1;
                
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
                }
                
            }
            
        }
        
        return dp[0][n-1];
        
    }
};