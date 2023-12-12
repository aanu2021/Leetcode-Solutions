class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax = 0, smax = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > fmax){
                smax = fmax;
                fmax = nums[i];
            }
            else if(nums[i] > smax){
                smax = nums[i];
            }
        }
        return ((fmax-1)*(smax-1));
    }
};