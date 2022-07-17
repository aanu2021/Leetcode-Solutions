// Bottom Up DP + Prefix Sum //

// Though the last approach is not optimized enough but it gives us a hint of some well-known optimization technique on DP //

// And that is using a prefix sum store the elements of transition phase , such that we don't need to recalculate them //

// Time Complexity : O(N*K) // 

// Verdict : AC  //


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
                
                ll value=prefix[j];
                
                ll l=min(i-1,j);
                
                ll left_boundary=j-l;
                
                if(left_boundary-1>=0){
                    
                    value=(value-prefix[left_boundary-1]+M)%M;
                    
                }
                
                dp[i][j]=value;
                
            }
            
        }
        
        return dp[n][k];
        
    }
};