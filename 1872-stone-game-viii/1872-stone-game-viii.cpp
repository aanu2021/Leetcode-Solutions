class Solution {
public:
    
    /*
    
    [d] --> d
    [c,d] --> max(c-d,d)
    [b,c,d] --> max(b-[c,d],c-d,d)
    [a,b,c,d] --> max(a-[b,c,d],b-[c,d],c-d,d)
    
    dp[n-1] --> prefix[n-1]
    dp[n-2] --> max(prefix[n-2]-dp[n-1],dp[n-1])
    dp[n-3] --> max(prefix[n-3]-dp[n-2],prefix[n-2]-dp[n-1],dp[n-1])
    .
    .
    .
    dp[i] --> max(prefix[i]-dp[i+1],dp[i+1])
    
    Here { prefix[i] - dp[i+1] } term is compared in each iteration whether it is maximum or not , otherwise we will continue with the rest of the dp[j] values
    
    */
    
    int stoneGameVIII(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        vector<int>dp(n);
        dp[n-2] = prefix[n-1];
        
        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+1],prefix[i+1]-dp[i+1]);
        }
        
        return dp[0];
        
    }
};
  
       
    