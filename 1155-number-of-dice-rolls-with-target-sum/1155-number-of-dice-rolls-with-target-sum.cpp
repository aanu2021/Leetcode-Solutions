class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    ll dp[32][1002];
    
    ll func(int i,int n,int k,int target){
        
        if(i==n){
            
            if(target==0){
                
                return 1LL;
                
            }
            
            else{
                
                return 0LL;
                
            }
            
        }
        
        if(dp[i][target]!=-1){
            
            return dp[i][target];
            
        }
        
        ll ans = 0LL;
        
        for(int move = 1;move <= k;move++){
            
            if(target >= move){
                
                ans = add(ans,func(i+1,n,k,target-move));
                
            }
            
        }
        
        return dp[i][target] = ans;
        
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        memset(dp,-1,sizeof(dp));
        
        ll ans = func(0,n,k,target);
        
        return ans;
        
    }
};