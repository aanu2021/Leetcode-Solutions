/*

Time Complexity  : O(N)
Space Complexity : O(1)

*/

class Solution {
public:
    
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxLen = 0;
        
        int l=0, r=0, bit=0;
        
        while(l<n && r<n){
            
            while((bit&nums[r])!=0){
                
                bit^=nums[l];
                
                l++;
                
            }
            
            bit|=nums[r];
            
            maxLen = max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};