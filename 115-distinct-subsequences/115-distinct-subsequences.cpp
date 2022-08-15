class Solution {
public:
    
    typedef unsigned long long ll;
    
    int numDistinct(string s, string t) {
        
        ll m=s.length();
        ll n=t.length();
        
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,0LL));
        
        for(ll i=0;i<=m;++i){
            dp[i][0]=1LL;
        }
        
        for(ll i=1;i<=m;++i){
            for(ll j=1;j<=n;++j){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
               
    }
};