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
        
        ll prev=1LL,curr=1LL;
        
        vector<ll>lastIndex(26,0LL);
        
        for(ll i=0;i<n;++i){
            
            curr=mul(2LL,prev);
            
            char ch=s[i]-'a';
            
            curr=(curr-lastIndex[ch]+M)%M;
            
            lastIndex[ch]=prev;
            
            prev=curr;
            
        }
        
        curr--;
        
        return curr;
        
    }
};