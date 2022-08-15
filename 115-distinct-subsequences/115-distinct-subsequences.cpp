class Solution {
public:
    
    typedef unsigned long long ll;
    
    int numDistinct(string s, string t) {
        
        ll m=s.length();
        ll n=t.length();
        
        vector<ll>dp(n+1,0LL);
        
        dp[0]=1LL;
        
        for(ll i=1;i<=m;++i){
            
            dp[0]=1LL;
            
            for(ll j=n;j>=1;--j){
                
                if(s[i-1]==t[j-1]){
                    
                    dp[j]+=dp[j-1];
                    
                }
                
                else{
                    
                    dp[j]=dp[j];
                    
                }
                
            }
            
        }
        
        return dp[n];
               
    }
};