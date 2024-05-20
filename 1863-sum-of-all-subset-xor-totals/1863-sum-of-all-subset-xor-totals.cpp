class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int orSum = 0;
        for(int &ele : nums){
            orSum |= ele;
        }
        return (orSum << (n-1));
    }
};