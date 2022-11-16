class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int pre = 1,suf = 1;
        for(int i=0;i<n;i++){
            ans[i]*=pre;
            pre*=nums[i];
            ans[n-i-1]*=suf;
            suf*=nums[n-i-1];
        }
        return ans;
    }
};