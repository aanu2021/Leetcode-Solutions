class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer;
        int rightSum = 0, leftSum = 0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++) rightSum += nums[i];
        for(int i=0;i<n;i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            answer.push_back(nums[i]);
            if(leftSum > rightSum){
                break;
            }
        }
        return answer;
    }
};

