class Solution {
public:
    
    /*
    
    
    s[0...i]
    t[0...j]
    
    dp[i][j] --> number of distinct subsequences present in s[0...i] in the form of t[0...j]
    
    dp[i][j] --> 
    
    Case 1. s[i]==t[j]
    
    (i) We can pick the i-th character and find the remaining t[0...j-1] inside s[0...i-1]
    
    (ii) We leave the i-th character and find the t[0...j] substring inside s[0...i-1] 
    
    
    Case 2. s[i]!=t[j]
    
    We leave the i-th character and find the t[0...j] substring inside s[0...i-1] 
    
    
    Case 1 : dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    
    Case 2 : dp[i][j] = dp[i-1][j]
    
    
    */
    
    
    int dp[1002][1002];
    
    int func(string &s,string &t,int i,int j){
        
        if(i<0 && j<0){
            return 1;
        }
        
        if(i>=0 && j<0){
            return 1;
        }
        
        if(i<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            
            return dp[i][j];
            
        }
        
        
        if(s[i]==t[j]){
            
           return dp[i][j]=func(s,t,i-1,j-1)+func(s,t,i-1,j);
            
        }
        
        else{
            
           return dp[i][j]=func(s,t,i-1,j);   
            
        }
        
    }
    
    int numDistinct(string s, string t) {
        
        int m=s.length();
        int n=t.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(s,t,m-1,n-1);
        
        return ans;
        
    }
};