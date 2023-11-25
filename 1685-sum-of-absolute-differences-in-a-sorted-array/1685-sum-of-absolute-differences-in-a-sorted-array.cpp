class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer(n,0);
        int rightSum = 0, leftSum = 0;
        for(int i=0;i<n;i++){
            rightSum += nums[i];
        }
        for(int i=0;i<n;i++){
            answer[i] = (i*nums[i]) - (leftSum) + (rightSum) - (n-i)*nums[i];
            rightSum -= nums[i];
            leftSum += nums[i];
        }
        return answer;
    }
};