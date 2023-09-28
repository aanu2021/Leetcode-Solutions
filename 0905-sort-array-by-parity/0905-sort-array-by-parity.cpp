class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low < high){
            while(low < high && nums[low]%2==0) low++;
            while(low < high && nums[high]%2!=0) high--;
            if(low < high) swap(nums[low],nums[high]);
            low++; high--;
        }
        return nums;
    }
};

// 4 2 1 3
// 0 1 2 3
    