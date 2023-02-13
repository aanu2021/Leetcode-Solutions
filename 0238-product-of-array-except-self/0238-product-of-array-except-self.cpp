class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cntZero = 0;
        for(int ele : nums){
            if(ele == 0) cntZero++;
        }
        int prod = 1;
        for(int ele : nums){
            if(ele == 0) continue;
            prod *= ele;
        }
        for(int i=0;i<n;i++){
            if(cntZero > 1){
                nums[i] = 0;
            }
            else if(cntZero == 1){
                if(nums[i]==0) nums[i] = prod;
                else           nums[i] = 0;
            }
            else{
                nums[i] = prod/nums[i];
            }
        }
        return nums;
    }
};
