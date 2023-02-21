class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            int currEleOcc = 1;
            if(mid-1>=0 && nums[mid-1]==nums[mid]) currEleOcc++;
            if(mid+1<n &&  nums[mid+1]==nums[mid]) currEleOcc++;
            if(currEleOcc == 1) return nums[mid];
            if(mid%2){
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else{
                if(mid+1 <n && nums[mid+1]==nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};