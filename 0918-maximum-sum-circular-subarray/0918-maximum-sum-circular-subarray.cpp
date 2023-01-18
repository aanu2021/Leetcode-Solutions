class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currMaxSum = 0;
        int currMinSum = 0;
        int totalSum = 0;
        for(int ele : nums){
            totalSum += ele;
            currMaxSum += ele;
            currMinSum += ele;
            maxSum = max(maxSum,currMaxSum);
            minSum = min(minSum,currMinSum);
            if(currMaxSum < 0){
                currMaxSum = 0;
            }
            if(currMinSum > 0){
                currMinSum = 0;
            }
        }
        if(maxSum < 0) return maxSum;
        else return max(maxSum,totalSum - minSum);
    }
};