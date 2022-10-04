/*

Time Complexity  : O(N*32)
Space Complexity : O(32)

*/

class Solution {
public:
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        
        int bit = 0;
        
        int l = 0, r = 0;
        
        while(l<n && r<n){
            
            while((bit&nums[r])!=0){
                
                bit^=nums[l++];
                
            }
            
            bit|=nums[r];
            
            maxLen = max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};