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
    
    int kInversePairs(int n, int k) {
        
        ll dp[n+1][k+1];
        
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                dp[i][j]=0LL;
            }
        }
        
        
        dp[0][0]=1LL;
        
        for(ll i=1;i<=n;i++){
            
            vector<ll>prefix(k+1,0LL);
            
            prefix[0]=dp[i-1][0];
            
            for(ll j=1;j<=k;j++){
                
                prefix[j]=add(prefix[j-1],dp[i-1][j]);
                
            }
            
            for(ll j=0;j<=k;j++){
                
                ll sum=prefix[j];
                
                ll l=min(j,i-1);
                
                ll left=j-l-1;
                
                if(left>=0){
                    
                    sum=(sum-prefix[left]+M)%M;
                    
                }
                
                dp[i][j]=sum;
                
            }
            
        }
        
        return mod(dp[n][k]);
        
    }
};