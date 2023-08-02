class Solution {
public:
    int trap(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int answer = 0;
        
        while(left <= right){
           if(nums[left] <= nums[right]){
               leftMax = max(leftMax, nums[left]);
               answer += (leftMax - nums[left]);
               left++;
           }else{
               rightMax = max(rightMax, nums[right]);
               answer += (rightMax - nums[right]);
               right--;
           } 
        }
        
        return answer;
    }
};