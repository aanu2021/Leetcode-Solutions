class Solution {
public:
    
    /*
    
    1-D DP Optimization
    
    Time Complexity  : O(M*N)
    Space Complexity : O(N)
    
    */
    
    typedef unsigned long long ll;
    
    int numDistinct(string s, string t) {
        
        ll m=s.length();
        ll n=t.length();
        
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,0LL));
        
        for(ll i=0;i<=m;++i){
            
            dp[i][0]=1LL;
            
        }
        
        
        s="*"+s;
        t="*"+t;
        
        for(ll i=1;i<=m;++i){
            
            for(ll j=1;j<=n;++j){
                
                if(s[i]==t[j]){
                    
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    
                }
                
                else{
                    
                    dp[i][j]=dp[i-1][j];
                    
                }
                
            }
            
        }
        
        return dp[m][n];
        
    }
};