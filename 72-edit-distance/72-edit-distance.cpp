class Solution {
public:    
            
    int func(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        
        if(i<0){
            
            return j+1;
            
        }
        
        if(j<0){
            
            return i+1;
            
        }
        
        if(dp[i][j]!=-1){
            
            return dp[i][j];
            
        }
        
        if(s1[i]==s2[j]){
            
            return dp[i][j]=func(s1,s2,i-1,j-1,dp);
            
        }
        
        else{
            
            int insert_ops=func(s1,s2,i,j-1,dp);
            int delete_ops=func(s1,s2,i-1,j,dp);
            int replace_ops=func(s1,s2,i-1,j-1,dp);
            
            return dp[i][j]=1+min({insert_ops,delete_ops,replace_ops});
            
        }
        
    }
    
    int minDistance(string s1, string s2) {
        
        int m=s1.length();
        int n=s2.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1.0));
        
        for(int i=1;i<=n;++i){
            dp[0][i]=i;
        }
        
        for(int i=1;i<=m;++i){
            dp[i][0]=i;
        }
        
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
        
        return dp[m][n];
        
    }
};