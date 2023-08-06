class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int max_prod = 1, min_prod = 1;
        for(int i=0;i<n;i++){
            int temp_max = max_prod;
            int temp_min = min_prod;
            max_prod = max({nums[i],nums[i]*temp_max,nums[i]*temp_min});
            min_prod = min({nums[i],nums[i]*temp_max,nums[i]*temp_min});
            ans = max({ans,max_prod,min_prod});
        }
        return ans;
    }
};