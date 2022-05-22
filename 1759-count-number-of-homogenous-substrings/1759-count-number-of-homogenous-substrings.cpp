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
    
    int countHomogenous(string s) {
        
        ll n=s.length();
        
        ll ans=0LL;
        
        for(ll i=0;i<n;i++){
            
            ll j=i;
            
            ll cnt=0LL;
            
            while(j<n && s[j]==s[i]){
                j++;
                cnt++;
            }
            
            ll curr=(cnt*(cnt+1))/2;
            
            ans=add(ans,curr);
            
            i=j;
            i--;
            
        }
        
        return ans;
        
    }
};