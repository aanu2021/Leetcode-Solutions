class Solution {
public:
    
    typedef long long ll;
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        ll n=stations.size();
        
        vector<ll>dp(n+1,0LL);
        
        dp[0]=(ll)startFuel;
        
        
        for(ll i=0;i<n;++i){
            
            for(ll j=i;j>=0;j--){
                
                if(dp[j]>=(ll)stations[i][0]){
                    
                    dp[j+1]=max(dp[j+1],dp[j]+(ll)stations[i][1]);
                    
                }
                
            }
            
        }
        
        if(dp[n]<target){
            
            return -1;
            
        }
        
        for(ll i=0;i<=n;++i){
            
            if(dp[i]>=target){
                
                return i;
                
            }
            
        }
        
        return -1;
        
    }
};