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
        
        vector<ll>dp(n+1,0LL);
        
        dp[0]=1LL;
        
        map<char,ll>mp;
        
        for(ll i=1;i<=n;i++){
            
            char ch=s[i-1];
            
            dp[i]=mul(2LL,dp[i-1]);
            
            if(mp.find(ch)!=mp.end()){
                
                ll j=mp[ch];
                
                dp[i]=((dp[i]-dp[j-1])%M+M)%M;
                
            }
            
            mp[ch]=i;
            
        }
        
        return mod(dp[n])-1;
        
    }
};