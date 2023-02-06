class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n,-1);
        int l = 0, r = n;
        int idx = 0;
        while(r < 2*n){
            ans[idx++] = nums[l++];
            ans[idx++] = nums[r++];
        }
        return ans;
    }
};