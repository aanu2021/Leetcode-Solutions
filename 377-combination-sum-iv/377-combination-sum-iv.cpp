// If the numbers are not unique , then we can insert them in a Set , as it is a variation of coin permutation , where we have an infinite supply of coins of particular type . //

// In order to allow negative numbers , we have a tight upper bound on sequence length , otherwise the total number of combinations that add up to target may reach INF //

class Solution {
public:
    
    typedef unsigned long long ll;
    
    int combinationSum4(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        vector<ll>dp(target+1,0LL);
        
        dp[0]=1LL;
        
        for(ll i=1;i<=target;++i){
            
            for(ll j=0;j<n;++j){
                
                if(nums[j]<=i){
                    
                    dp[i]+=dp[i-nums[j]];
                    
                }
                
            }
            
        }
        
        return dp[target];
        
    }
};