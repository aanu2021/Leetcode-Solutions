class Solution {
public:
    int change(int k, vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>dp(k+1,0);
        
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            
            for(int j=nums[i];j<=k;j++){
                
                dp[j]=dp[j]+dp[j-nums[i]];
                
            }
            
        }
        
        return dp[k];
        
    }
};