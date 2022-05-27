class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxval=*max_element(nums.begin(),nums.end());
        
        vector<int>v(maxval+1,0);
        
        for(int i:nums){
            v[i]++;
        }
        
        vector<int>dp(maxval+1,0);
        
        dp[0]=0;
        dp[1]=max(dp[0],v[1]);
        
        for(int i=2;i<=maxval;i++){
            
            dp[i]=max(dp[i-1],dp[i-2]+(v[i]*i));
            
        }
        
        return dp[maxval];
        
    }
};