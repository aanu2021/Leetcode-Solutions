class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int currSum = 1;
        for(int i=1;i<n;i++){
            if(currSum == 0){
                element = nums[i];
            }
            if(element == nums[i]){
                currSum++;
            }
            else{
                currSum--;
            }
        }
        return element;
    }
};