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
            
            return dp[i][j] = func(s,p,i-1,j,dp) || func(s,p,i,j-1,dp);
            
        }
            
        return dp[i][j];
        
    }
    
    bool isMatch(string s, string p) {
        
        int m = s.length();
        int n = p.length();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        int ans = func(s,p,m-1,n-1,dp);
        
        if(ans==1){
            return true;
        }else{
            return false;
        }
        
    }
};