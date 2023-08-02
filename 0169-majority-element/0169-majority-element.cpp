class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int currSum = 1;
        int element = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == element){
                currSum++;
            }
            else{
                currSum--;
                if(currSum < 0){
                    currSum = 1;
                    element = nums[i];
                }
            }
        }
        return element;
    }
};

