class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>dp(n,1);
        
        sort(nums.begin(),nums.end());
        
        vector<int>prev(n,-1);
        
        int maxLen=0;
        
        for(int i=1;i<n;++i){
            
            for(int j=0;j<i;++j){
                
                if(nums[i]%nums[j]==0){
                    
                    if(dp[i]<1+dp[j]){
                        
                        dp[i]=1+dp[j];
                        prev[i]=j;
                        
                    }
                    
                }
                
            }
            
        }
        
        
        for(int i=0;i<n;++i){
            
            maxLen=max(maxLen,dp[i]);
            
        }
        
        int ending_index=-1;
        
        for(int i=0;i<n;++i){
            
            if(dp[i]==maxLen){
                
                ending_index=i;
                break;
                
            }
            
        }
        
        vector<int>div_subset;
        
        while(ending_index!=-1){
            
            div_subset.push_back(nums[ending_index]);
            
            ending_index=prev[ending_index];
            
        }
        
        reverse(div_subset.begin(),div_subset.end());
        
        return div_subset;
        
    }
};