class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        for(int ele : nums){
            xorSum ^= ele;
        }
        return xorSum;
    }
};