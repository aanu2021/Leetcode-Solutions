class Solution {
public:
    
    typedef long long ll;
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0LL;
        ll minCost = 1e16;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i];
            cnt += ((ele^k) > ele ? 1 : 0);
            sum += (ll)max(ele, ele^k);
            minCost = min(minCost, (ll)abs(ele - (ele^k)));
        }
        return sum - (cnt%2 ? minCost : 0);
    }
};