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
    
    
    int numMusicPlaylists(int N, int L, int K) {
        
        vector<vector<ll>>dp(L+1,vector<ll>(N+1,0LL));
        
        dp[0][0]=1LL;
        
        for(ll i=1;i<=L;i++){
            
            for(ll j=1;j<=N;j++){
                
                ll left=mul(dp[i-1][j-1],N-j+1);
                
                ll right=mul(dp[i-1][j],max(0LL,j-K));
                
                dp[i][j]=add(left,right);
                
            }
            
        }
        
        return mod(dp[L][N]);
        
    }
};