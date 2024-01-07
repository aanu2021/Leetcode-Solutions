class Solution {
public:
    
    typedef long long ll;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll,int>>dp(n);
        int answer = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff = (ll)nums[j] - (ll)nums[i];
                if(dp[j].find(diff) != dp[j].end()){
                    answer += dp[j][diff];
                }
                dp[i][diff] += (1 + dp[j][diff]);
            }
        }
        return answer;
    }
};

/*

2 4 6 8 10
0 1 2 3  4
    
dp[1][2] = 1
dp[2][2] = 2    
dp[2][4] = 1    
dp[3][2] = 3 
dp[3][4] = 1
dp[3][6] = 1 
dp[4][2] = 4 
dp[4][4] = 2 
dp[4][6] = 1
dp[4][8] = 1    
    
answer = 1 + 2 + 3 + 1 = 7 

*/
    