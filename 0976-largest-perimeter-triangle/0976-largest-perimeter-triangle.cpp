class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int maxi_per = 0;
        
        int n = nums.size();
        
        for(int i=n-3;i>=0;i--){
            
            if(nums[i]+nums[i+1] > nums[i+2]){
                
                maxi_per = nums[i] + nums[i+1] + nums[i+2];
                
                break;
                
            }
            
        }
        
        return maxi_per;
        
    }
};