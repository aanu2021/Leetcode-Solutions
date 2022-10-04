class Solution {
public:
    
    int func(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        
        if(i<0 && j<0){
            return 1;
        }
        
        if(i<0 && j>=0){
            
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return 0;
                }
            }
            
            return 1;
            
        }
        
        if(i>=0 && j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            
            return dp[i][j];
            
        }
        
        dp[i][j] = 0;
        
        if(s[i]==p[j] || p[j]=='?'){
            
            return dp[i][j] = func(s,p,i-1,j-1,dp);
            
        }
        
        else if(p[j]=='*'){
            
            dp[i][j] = func(s,p,i,j-1,dp);
            
            for(int k=0;k<=i;k++){
                
                dp[i][j] = max(dp[i][j],func(s,p,i-k-1,j-1,dp));
                
                if(dp[i][j]){
                    return dp[i][j];
                }
                
            }
            
            return dp[i][j];
            
        }
            
        return dp[i][j];
        
    }
    
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0] = true;
        
        s="*"+s;
        p="*"+p;
        
        for(int i=1;i<=n;i++){
            if(p[i]=='*'){
                dp[0][i]=dp[0][i-1];
            }else{
                break;
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        
        return dp[m][n];
        
    }
};