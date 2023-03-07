class Solution {
public:
    
    typedef long long ll;
    
    bool canMake(vector<int>&nums,ll mid,int k){
        ll curr = 0LL;
        for(int i=0;i<nums.size();i++){
            curr += (ll)(mid/nums[i]);
            if(curr >= k) return true;
        }
        return false;
    }
    
    long long minimumTime(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        ll low = 0LL , high = (ll)((ll)mini*(ll)k);
        ll ans = -1LL;
        while(low <= high){
            ll mid = (low + high)/2;
            if(canMake(nums,mid,k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};