class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;
        int k = n - 3;
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-k;i++){
            int diff = nums[i+k-1] - nums[i];
            mini = min(mini, diff);
        }
        return mini;
    }
};



