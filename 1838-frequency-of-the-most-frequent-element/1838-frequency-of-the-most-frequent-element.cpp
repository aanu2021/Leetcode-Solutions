class Solution {
public:
    
    typedef long long ll;
    
    ll findOps(vector<int>&nums,int l,int r,ll currSum){
        ll ops = (ll)((ll)nums[r]*(ll)(r-l+1));
        ops -= currSum;
        return ops;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = 0, maxLen = 0;
        ll currSum = 0LL;
        while(r < n){
            currSum += (ll)nums[r];
            while(l <= r && findOps(nums,l,r,currSum) > k){
                currSum -= (ll)nums[l];
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};