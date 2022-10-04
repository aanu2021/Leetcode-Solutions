class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int>ans;
        
        int n=nums.size();
        
        int xorval = 0;
        
        for(int ele:nums){
            xorval ^= ele;
        }
        
       //   xorval = xor1 ^ xor2   //
        
        int xor1 = 0,xor2 = 0;
        
        int msb=0;
        
        for(int i=31;i>=0;i--){
            if((xorval&(1<<i))){
                msb=i;
                break;
            }
        }
        
        for(int i=0;i<n;++i){
            
            if((nums[i]&(1<<msb))){
                
                xor1 ^= nums[i];
                
            }
            
        }
        
        return {xor1 , xorval^xor1};
        
    }
};