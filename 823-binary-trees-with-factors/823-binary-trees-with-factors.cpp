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
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        ll n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        vector<ll>dp(n,1LL);
        
        unordered_map<ll,ll>index;
        
        for(ll i=0;i<n;++i){
            index[arr[i]]=i;
        }
        
        for(ll i=1;i<n;++i){
            
            for(ll j=0;j<i;++j){
                
                if(arr[i]%arr[j]==0){
                    
                    ll rest=arr[i]/arr[j];
                    
                    if(index.find(rest)!=index.end()){
                        
                        dp[i]=add(dp[i],mul(dp[j],dp[index[rest]]));
                        
                        
                    }
                    
                }
                
            }
            
        }
        
        
        ll total_ways=0LL;
        
        for(ll i=0;i<n;++i){
            
            total_ways=add(total_ways,dp[i]);
            
        }
        
        return total_ways;
        
    }
};