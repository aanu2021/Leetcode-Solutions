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
    
    ll dp[1002][1002];
    
    ll func(vector<vector<int>>&grid,int i,int j,int m,int n,int prev){
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=prev){
            
            return 0LL;
            
        }
        
        if(dp[i][j]!=-1LL){
            
            return dp[i][j];
            
        }
        
        ll curr_paths=1LL;
        
        ll op1=func(grid,i+1,j,m,n,grid[i][j]);
        ll op2=func(grid,i-1,j,m,n,grid[i][j]);
        ll op3=func(grid,i,j+1,m,n,grid[i][j]);
        ll op4=func(grid,i,j-1,m,n,grid[i][j]);
        
        curr_paths=add(curr_paths,op1);
        curr_paths=add(curr_paths,op2);
        curr_paths=add(curr_paths,op3);
        curr_paths=add(curr_paths,op4);
        
        return dp[i][j] = curr_paths;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        ll m=grid.size();
        ll n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        ll total_paths=0LL;
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(dp[i][j]==-1){
                    
                    ll curr_paths=func(grid,i,j,m,n,-1);
                    
                    dp[i][j]=curr_paths;
                    
                }
                
                total_paths=add(total_paths,dp[i][j]);
                
            }
            
        }
        
        return total_paths;
        
    }
};


