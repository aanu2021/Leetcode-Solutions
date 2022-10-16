class Solution {
public:
    
    int func(vector<int>&nums,int i,int n,int k,vector<vector<int>>&dp){
        
        if(i>=n){
            
            if(k==0){
                return 0;
            }
            
            else{
                return 1e9;
            }
            
        }
        
        if(dp[i][k]!=-1){
            
            return dp[i][k];
            
        }
        
        int ans = 1e9;
        
        int currmax = nums[i];
            
        for(int j=i;j<n;j++){
            
            currmax=max(currmax,nums[j]);
            
            if(k>0){
                
                ans = min(ans,currmax + func(nums,j+1,n,k-1,dp));
                
            }
            
        }    
        
        return dp[i][k] = ans;
        
    }
    
    int minDifficulty(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        
        int ans = func(nums,0,n,k,dp);
        
        if(ans>=1e9) return -1;
        
        return ans;
        
    }
};


// dp[i][k] 

// i-th days
// k of powers