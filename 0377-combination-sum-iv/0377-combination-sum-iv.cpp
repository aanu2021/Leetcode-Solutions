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


// #include<bits/stdc++.h>
// using namespace std;

// class Solution{
    
//     public:
    
//     unordered_map<int,unordered_map<int,int>>dp;
    
//     int func(vector<int>&nums,int len,int target){
        
//         if(len==0){
            
//             if(target==0){
                
//                 return 1;
                
//             }
            
//             else{
                
//                 return 0;
                
//             }
            
//         }
        
//         if(dp.find(len)!=dp.end() && dp[len].find(target)!=dp[len].end()){
            
//             return dp[len][target];
            
//         }
        
//         int ans=0;
        
//         for(int num:nums){
            
//             ans+=func(nums,len-1,target-num);
            
//         }
        
//         return dp[len][target] = ans;
        
//     }
    
//     int combinationSum(vector<int>&nums,int target,int len){
        
//         int n=nums.size();
        
//         int ans=0;
        
//         for(int currlen=1;currlen<=len;currlen++){
            
//             ans+=func(nums,currlen,target);
            
//         }
        
//         return ans;
        
//     }
    
// };

// int main(){
    
//     vector<int>nums={1,2,3,-1};
    
//     Solution obj;
    
//     cout<<obj.combinationSum(nums,4,4)<<"\n";
    
//     return 0;
    
// }