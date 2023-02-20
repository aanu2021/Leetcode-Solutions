class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        if(nums[0] > target) return 0;
        if(nums.back() < target) return n;
        int index = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                index = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return index + 1;
    }
};