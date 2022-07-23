class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
        int limit=(2*numSlots);
        
        while(nums.size()<limit){
            nums.push_back(0);
        }
        
        int n=nums.size();
        
        vector<int>dp(1<<n,0);
        
        dp[0]=0;
        
        for(int mask=1;mask<(1<<n);mask++){
            
            int cnt=__builtin_popcount(mask);
            
            int slot=(cnt+1)/2;
            
            for(int i=0;i<n;++i){
                
                if((mask&(1<<i))){
                    
                    dp[mask]=max(dp[mask],dp[mask^(1<<i)]+(nums[i]&slot));
                    
                }
                
            }
            
        }
        
        return dp[(1<<n)-1];
        
    }
};