class Solution {
public:
    typedef long long ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0LL;
        vector<unordered_map<ll,ll>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll) ((ll)nums[i] - (ll)nums[j]);
                ll cnt = 0LL;
                if(dp[j].find(diff)!=dp[j].end()){
                    cnt = dp[j][diff];
                }
                ans+=cnt;
                dp[i][diff]+=(cnt+1);
            }
        }
        return ans;
    }
};