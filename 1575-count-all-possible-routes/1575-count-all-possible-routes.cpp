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
    
    ll dp[102][202];
    
    ll func(vector<int>&arr,int i,int target,int fuel,int n){
        
        if(fuel<0){
            
            return 0LL;
            
        }
        
        if(dp[i][fuel]!=-1){
            
            return dp[i][fuel];
            
        }
        
        ll cnt=0LL;
        
        if(i==target) cnt++;
        
        for(int j=0;j<n;++j){
            
            if(i==j) continue;
            
            cnt=add(cnt,func(arr,j,target,fuel-abs(arr[i]-arr[j]),n));
            
        }
        
        return dp[i][fuel] = cnt;
        
    }
    
    int countRoutes(vector<int>& arr, int start, int finish, int fuel) {
        
        int n=arr.size();
        
        for(int i=0;i<=n;++i){
            for(int j=0;j<=fuel;++j){
                dp[i][j]=-1;
            }
        }
        
        ll ans = func(arr,start,finish,fuel,n);
        
        return ans;
        
    }
};