class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
        
        int arraysum=0;
        
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        
        int tempmax=0,tempmin=0;
        
        for(int i=0;i<n;i++){
            
            arraysum+=nums[i];
            
            tempmax+=nums[i];
            
            tempmin+=nums[i];
            
            maxsum=max(maxsum,tempmax);
            
            minsum=min(minsum,tempmin);
            
            if(tempmax<0){
                tempmax=0;
            }
            
            if(tempmin>0){
                tempmin=0;
            }
            
        }
        
        if(arraysum==minsum){
            return maxsum;
        }else{
            return max(maxsum,arraysum-minsum);
        }
        
    }
};