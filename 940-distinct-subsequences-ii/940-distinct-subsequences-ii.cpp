class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    int distinctSubseqII(string s) {
        
        ll n=s.length();
        
        vector<ll>dp(n+1,1LL);
        
        dp[0]=1LL;
        
        s="*"+s;
        
        vector<ll>lastIndex(26,-1);
        
        for(ll i=1;i<=n;++i){
            
            dp[i]=mul(2LL,dp[i-1]);
            
            char ch=s[i];
            
            if(lastIndex[ch-'a']!=-1){
                
                dp[i]=(dp[i]-dp[lastIndex[ch-'a']-1]+M)%M;
                
            }
            
            lastIndex[ch-'a']=i;
            
        }
        
        return (dp[n]-1+M)%M;
        
    }
};