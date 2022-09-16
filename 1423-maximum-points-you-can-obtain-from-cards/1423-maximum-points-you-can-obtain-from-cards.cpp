class Solution {
public:
    int maxScore(vector<int>&nums, int k) {
        
        int n=nums.size();
        
        int minval=INT_MAX;
        
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        
        int currsum=0;
        
        k=n-k;
        
        for(int i=0;i<k;++i){
            
            currsum+=nums[i];
            
        }
        
        minval=currsum;
        
        for(int i=k;i<n;++i){
            
            currsum+=nums[i];
            
            currsum-=nums[i-k];
            
            minval=min(minval,currsum);
            
        }
        
        return (total_sum-minval);
        
    }
};