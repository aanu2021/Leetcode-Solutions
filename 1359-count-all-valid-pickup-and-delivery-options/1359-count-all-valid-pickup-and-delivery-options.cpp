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
    
    ll func(ll x){
        return (x*(x+1))/2;
    }
    
    int countOrders(int n) {
        
        if(n==1){
            return 1;
        }
        
        vector<ll>dp(n+1,0LL);
        
        dp[1]=1LL;
        
        for(ll i=2;i<=n;i++){
            
            ll additional=func(2*i-1);
            
            ll curr=mul(additional,dp[i-1]);
            
            dp[i]=mod(curr);
            
        }
        
        return dp[n];
        
    }
};