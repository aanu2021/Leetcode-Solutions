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
    
    ll dp[55][55][55];
    
    ll func(ll i,ll j,ll k,ll m,ll n){
        
        if(k<0){
            
           return 0LL; 
            
        }
        
        if(i<0 || j<0 || i>=m || j>=n){
            
            return 1LL;
            
        }
        
        
        if(dp[i][j][k]!=-1){
            
            return dp[i][j][k];
            
        }
        
        
        ll op1=func(i+1,j,k-1,m,n);
        ll op2=func(i-1,j,k-1,m,n);
        ll op3=func(i,j+1,k-1,m,n);
        ll op4=func(i,j-1,k-1,m,n);
        
        
        dp[i][j][k]=add(add(op1,op2),add(op3,op4));
        
        return dp[i][j][k];
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        for(ll i=0;i<=m;++i){
            for(ll j=0;j<=n;++j){
                for(ll k=0;k<=maxMove;++k){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        ll ans=func(startRow,startColumn,maxMove,m,n);
        
        return mod(ans);
    }
};