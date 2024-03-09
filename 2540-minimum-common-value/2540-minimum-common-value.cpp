class Solution {
public:
    
    bool found(vector<int>&nums, int target){
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return getCommon(nums2,nums1);
        for(int &num : nums1){
            if(found(nums2,num)) return num;
        }
        return -1;
    }
};