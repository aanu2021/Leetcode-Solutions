class Solution {
public:
    
    typedef long long ll;
    
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        ll add_sum = 0LL;
        ll curr_sum = 0LL;
        int idx = n-1;
        for(int i=0;i<n;i++){
            curr_sum += (ll)nums[i]*(ll)i;
        }
        ll ans = curr_sum;
        for(int i=0;i<n;i++){
            add_sum += (ll)nums[i];
        }
        for(int i=n-1;i>=1;i--){
            curr_sum -= (ll)nums[i]*(ll)(n-1);
            curr_sum += add_sum;
            curr_sum -= (ll)nums[i];
            ans = max(ans,curr_sum);
        }
        return ans;
    }
};

    