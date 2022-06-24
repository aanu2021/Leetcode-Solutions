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
    
//     ll dp[105][105];
    
//     ll func(ll n,ll l,ll K,ll N,ll L){
        
//         if(l==0){
            
//             if(n==0){
//                 return 1;
//             }
            
//             else{
//                 return 0;
//             }
            
//         }
        
//         if(l<0 || n<0){
//             return 0;
//         }
        
//         if(dp[n][l]!=-1){
//             return dp[n][l];
//         }
        
//         ll intro=mul(func(n-1,l-1,K,N,L),(ll)(N-n+1));
        
//         ll again=mul(func(n,l-1,K,N,L),max(0LL,(ll)n-K));
        
//         return dp[n][l] = add(intro,again);
        
//     }
    
    int numMusicPlaylists(int N, int L, int K) {
        
        vector<vector<ll>>dp(L+1,vector<ll>(N+1,0LL));
        
        dp[0][0]=1LL;
        
        for(ll i=1;i<=L;++i){
            
            for(ll j=1;j<=N;++j){
                
                ll intro=mul(dp[i-1][j-1],(ll)(N-j+1));
                
                ll again=mul(dp[i-1][j],max(0LL,j-K));
                
                dp[i][j]=add(intro,again);
                
            }
            
        }
        
        return mod(dp[L][N]);
        
    }
};