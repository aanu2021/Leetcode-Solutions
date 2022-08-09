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
    
    int numberOfUniqueGoodSubsequences(string s) {
    
        ll n=s.length();
        
        ll cnt0=0LL,cnt1=0LL;
        
        bool hasZero=false;
        
        for(ll i=0;i<n;++i){
            
            if(s[i]=='0'){
                
                cnt0=add(cnt0,cnt1);
                hasZero=true;
                
            }
            
            else{
                
                cnt1=add(cnt0,add(cnt1,1LL));
                
            }
            
        }
        
        return mod(cnt0+cnt1+hasZero);
        
    }
};