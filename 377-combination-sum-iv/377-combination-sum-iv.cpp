// Coin Permutation //

// Time Complexity : O(N*target) //

class Solution {
public:
    
       typedef unsigned long long ll;
    
//     int dp[1001];
    
//     int func(vector<int>&nums,int target){
        
//         if(dp[target]!=-1){
//             return dp[target];
//         }
        
//         int ans=0;
        
//         for(int num:nums){
            
//             if(num<=target){
                
//                 ans+=func(nums,target-num);
                
//             }
            
//         }
        
//         return dp[target] = ans;
        
//     }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        
        vector<ll>dp(target+1,0);
        
       // memset(dp,-1,sizeof(dp));
        
        dp[0]=1LL;
        
        for(int i=1;i<=target;++i){
            
            for(int j=0;j<nums.size();++j){
                
                if(nums[j]<=i){
                    
                    dp[i]+=dp[i-nums[j]];
                    
                }
                
            }
            
        }
        
       // int ans=func(nums,target);
        
        return dp[target];
        
    }
};