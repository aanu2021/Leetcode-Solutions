class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int maxLen=0;
        
        int l=0,r=0;
        
        int count=0;
        
        while(l<n && r<n){
            
            if(nums[r]==0){
                count++;
            }
            
            while(l<=r && count>k){
                
               if(nums[l]==0){
                   count--;
               }
                
               l++; 
                
            }
            
            maxLen=max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};