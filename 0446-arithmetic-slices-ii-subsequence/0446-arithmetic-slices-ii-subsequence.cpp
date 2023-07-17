class Solution {
public:
    
    typedef long long ll;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<ll,ll>>dp(n);
        
        ll answer = 0LL;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll)nums[i] - (ll)nums[j];
                int cnt = 0;
                if(dp[j].find(diff) != dp[j].end()){
                    cnt = dp[j][diff];
                }
                answer += cnt;
                dp[i][diff] += (ll)(1 + cnt);
            }
        }
        
        return (int)answer;
        
    }
};

/*

2 4 6 8 10
    
atleast three elements  

dp[i][diff] = number of arithmetic subsequence ending at index i, 

*/