class Solution {
public:
    
    typedef long long ll;
    
    int longestArithSeqLength(vector<int>& nums) {
      
        ll n=nums.size();
        
        vector<vector<ll>>dp(n+1,vector<ll>(1005,0LL));
        
        ll maxLen=0LL;
        
        for(ll i=1;i<n;i++){
            
            for(ll j=0;j<i;j++){
                
                ll diff=(ll)nums[i]-(ll)nums[j]+500;
                
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                
                maxLen=max(maxLen,dp[i][diff]);
                
            }
            
        }
        
        return maxLen+1;
        
    }
};