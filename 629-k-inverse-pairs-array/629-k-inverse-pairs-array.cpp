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
        
        memset(dp,0LL,sizeof(dp));
        
        dp[0][0] = 1LL;
        
        for(int i=1;i<=n;++i){
            
            vector<int>prefix_sum(k+1,0);
            
            for(int j=0;j<=k;++j){
                
                prefix_sum[j] = dp[i-1][j];
                
            }
            
            for(int j=1;j<=k;++j){
                
                prefix_sum[j] = add(prefix_sum[j],prefix_sum[j-1]);
                
            }
            
            for(int j=0;j<=k;++j){
                
                int l = min(i-1,j);
                
                dp[i][j] = prefix_sum[j] - (j-l-1>=0 ? prefix_sum[j-l-1] : 0LL);
                
                dp[i][j] += M;
                dp[i][j] %= M;
                
            }
            
        }
        
        return dp[n][k];
        
    }
};