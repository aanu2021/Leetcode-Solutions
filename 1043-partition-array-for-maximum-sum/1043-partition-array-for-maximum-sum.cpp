class Solution {
public:
    
    typedef long long ll;
    
    ll dp[502];
    
    ll func(vector<int>&arr,ll i,ll k,ll n){
        
        if(i>=n){
            
           return 0;
            
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        ll curr_score=-1e9;
        
        ll curr_max=arr[i];
        
        for(ll j=i;j<=min(n-1,i+k-1);++j){
            
            curr_max=max(curr_max,(ll)arr[j]);
            
            curr_score=max(curr_score,(curr_max*(j-i+1))+func(arr,j+1,k,n));
            
        }
        
        return dp[i]=curr_score;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        ll n=arr.size();
        
        for(ll i=0;i<=n;++i){
            dp[i]=-1LL;
        }
        
        ll ans=func(arr,0,k,n);
        
        return ans;
        
    }
};