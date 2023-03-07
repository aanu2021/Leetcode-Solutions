class Solution {
public:
    
    typedef long long ll;
    
    bool canMake(vector<int>&nums,ll currTime,int k){
        ll trips = 0LL;
        for(int i=0;i<nums.size();i++){
            if(trips >= k) return true;
            trips += (ll)(currTime/nums[i]);
        }
        return trips >= k;
    }
    
    long long minimumTime(vector<int>& nums, int k) {
        int n = nums.size();
        ll low = 0LL , high = 1e15;
        ll ans = -1LL;
        while(low <= high){
            ll mid = low + (high-low)/2;
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