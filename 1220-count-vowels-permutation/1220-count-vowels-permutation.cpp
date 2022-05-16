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
    
    int countVowelPermutation(int n) {
        
        if(n==1){
            return 5;
        }
        
        vector<vector<ll>>dp(n+1,vector<ll>(5,0LL));
        
        dp[1][0]=1LL;
        dp[1][1]=1LL;
        dp[1][2]=1LL;
        dp[1][3]=1LL;
        dp[1][4]=1LL;
        
        for(ll i=2;i<=n;i++){
            
            ll curr=0LL;
            
            curr=add(curr,dp[i-1][1]);
            curr=add(curr,dp[i-1][2]);
            curr=add(curr,dp[i-1][4]);
            
            dp[i][0]=curr;
            
            curr=0LL;
            
            curr=add(curr,dp[i-1][0]);
            curr=add(curr,dp[i-1][2]);
            
            dp[i][1]=curr;
            
            curr=0LL;
            
            curr=add(curr,dp[i-1][1]);
            curr=add(curr,dp[i-1][3]);
            
            dp[i][2]=curr;
            
            curr=0LL;
            
            curr=add(curr,dp[i-1][2]);
            
            dp[i][3]=curr;
            
            curr=0LL;
            
            curr=add(curr,dp[i-1][2]);
            curr=add(curr,dp[i-1][3]);
            
            dp[i][4]=curr;
            
        }
        
        ll ans=0LL;
        
        for(ll i=0;i<5;i++){
            ans=add(ans,dp[n][i]);
        }
        
        return ans;
        
    }
};