class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        
        int minLen=INT_MAX;
        
        int l=0,r=0;
        
        int currsum=0;
        
        while(l<n && r<n){
            
            currsum+=nums[r];
            
            while(currsum>=target && l<=r){
                
                minLen=min(minLen,r-l+1);
                
                currsum-=nums[l];
                
                l++;
                
            }
            
            r++;
            
        }
        
        if(minLen==INT_MAX){
            return 0;
        }else{
            return minLen;
        }
        
    }
};