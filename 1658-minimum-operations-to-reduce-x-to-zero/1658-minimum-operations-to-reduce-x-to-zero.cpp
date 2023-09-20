class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target < x) return -1;
        if(target == x) return n;
        target = target - x;
        int maxLen = 0, l = 0, r = 0;
        int currSum = 0;
        while(r<n){
            currSum += nums[r];
            while(l<=r && currSum > target){
                currSum -= nums[l];
                l++;
            }
            if(currSum == target){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        if(maxLen == 0) return -1;
        else return n-maxLen;
    }
};