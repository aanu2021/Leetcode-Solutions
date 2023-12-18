class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int fmax = -1, smax = -1;
        int fmin = 100000000, smin = 100000000;
        for(int i=0;i<n;i++){
            if(nums[i] > fmax){
                smax = fmax;
                fmax = nums[i];
            }
            else if(nums[i] > smax){
                smax = nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] < fmin){
                smin = fmin;
                fmin = nums[i];
            }
            else if(nums[i] < smin){
                smin = nums[i];
            }
        }
        return ((fmax*smax) - (fmin*smin));
    }
};