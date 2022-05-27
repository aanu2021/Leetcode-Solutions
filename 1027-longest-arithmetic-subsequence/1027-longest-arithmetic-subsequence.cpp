class Solution {
public:
    
    typedef long long ll;
    
    int longestArithSeqLength(vector<int>& nums) {
      
        ll n=nums.size();
        
        vector<unordered_map<ll,ll>>dp(n);
        
        ll maxLen=0LL;
        
        for(ll i=1;i<n;i++){
            
            for(ll j=0;j<i;j++){
                
                ll diff=(ll)nums[i]-(ll)nums[j];
                
                if(dp[j].find(diff)==dp[j].end()){
                    
                    dp[i][diff]=1LL;
                    
                }
                
                else{
                    
                    dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                    
                }
                
                maxLen=max(maxLen,dp[i][diff]);
                
            }
            
        }
        
        return maxLen+1;
        
    }
};