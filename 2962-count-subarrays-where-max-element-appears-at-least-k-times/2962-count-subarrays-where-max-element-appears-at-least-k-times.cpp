class Solution {
public:
    
    typedef long long ll;
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll total = (((ll)n*(ll)(n+1))/2LL);
        int l = 0, r = 0, count = 0;
        ll cnt = 0LL;
        int maxi = *max_element(nums.begin(),nums.end());
        while(r < n){
            count += (nums[r] == maxi);
            while(l <= r && count >= k){
                count -= (nums[l] == maxi);
                l++;
            }
            cnt += (ll)(r-l+1);
            r++;
        }
        return total - cnt;
    }
};