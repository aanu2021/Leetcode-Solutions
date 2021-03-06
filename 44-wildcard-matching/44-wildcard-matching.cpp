class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=s.length();
        int n=p.length();
        
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0]=true;
        
        s="*"+s;
        p="*"+p;
        
        
        for(int i=1;i<=n;i++){
         
            if(p[i]=='*'){
                dp[0][i]=dp[0][i-1];
            }
            else{
                dp[0][i]=false;
            }
            
        }
        
        
        for(int i=1;i<=m;++i){
            
            for(int j=1;j<=n;++j){
                
                if(s[i]==p[j] || p[j]=='?'){
                    
                    dp[i][j]=dp[i-1][j-1];
                    
                }
                
                else if(p[j]=='*'){
                    
                    dp[i][j]=dp[i][j-1];
                    
                    for(int k=i-1;k>=0;k--){
                        
                        dp[i][j]=dp[i][j]||dp[k][j-1];
                        
                    }
                    
                }
                
            }
            
        }
        
        return dp[m][n];
        
    }
};