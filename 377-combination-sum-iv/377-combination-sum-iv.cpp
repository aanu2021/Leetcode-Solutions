// Coin Permutation //

class Solution {
public:
    
    int dp[1001];
    
    int func(vector<int>&nums,int target){
        
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int ans=0;
        
        for(int num:nums){
            
            if(num<=target){
                
                ans+=func(nums,target-num);
                
            }
            
        }
        
        return dp[target] = ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        memset(dp,-1,sizeof(dp));
        
        dp[0]=1;
        
        int ans=func(nums,target);
        
        return ans;
        
    }
};