class Solution {
public:
    
    typedef long long ll;
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        ll n=arr.size();
        
        vector<ll>dp(n,0LL);
        
        dp[n-1]=arr[n-1];
        
        for(ll i=n-2;i>=0;i--){
            
            ll max_score=0LL;
            
            ll curr_max=0LL;
            
            for(ll j=i;j<=min(i+k-1,n-1);++j){
                
                curr_max=max(curr_max,(ll)arr[j]);
                
                ll curr_score=(curr_max*(j-i+1));
                
                if(j+1<n){
                    
                   curr_score+=dp[j+1];
                    
                }
                
                max_score=max(max_score,curr_score);
                
            }
            
            dp[i]=max_score;
            
        }
        
        return dp[0];
        
    }
};