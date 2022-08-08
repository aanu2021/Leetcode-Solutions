class Solution {
public:
    
    int dp[2502];
    
    int func(vector<int>&nums,int i,int n){
        
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            
            return dp[i];
            
        }
        
        int maxLen=1; // Skip these index 
        
        int currLen=1;   // Pick these index
        
        for(int j=i+1;j<n;++j){
            
            if(nums[i]<nums[j]){
                
                currLen=max(currLen , 1 + func(nums,j,n) );
                
            }
            
        }
        
        maxLen=max(maxLen,currLen);
        
        return dp[i]=maxLen;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=0;i<=n;++i){
            dp[i]=-1;
        }
        
        int maxLen=0;
        
        for(int i=0;i<n;++i){
            
            if(dp[i]==-1){
                
                maxLen=max(maxLen,func(nums,i,n));
                
            }
            
        }
        
        // for(int i=0;i<n;++i){
        //     cout<<dp[i]<<" ";
        // }cout<<"\n";
        
        return maxLen;
        
    }
};