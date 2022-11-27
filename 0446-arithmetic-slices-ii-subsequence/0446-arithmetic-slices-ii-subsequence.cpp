class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<ll,ll>>dp(n);
        ll ans = 0LL;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll)((ll)nums[i] - (ll)nums[j]);
                ll cnt = 0LL;
                if(dp[j].find(diff)!=dp[j].end()){
                    cnt = dp[j][diff];
                }
                dp[i][diff]+= 1 + cnt;
                ans += cnt;
            }
        }
        return ans;
    }
};