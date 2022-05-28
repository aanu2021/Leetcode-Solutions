class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
      int xorsum=0;
        
        int i=0;
        
        for(i=0;i<nums.size();i++){
            xorsum=xorsum^i^nums[i];
        }
        
        return xorsum^i;
        
    }
};