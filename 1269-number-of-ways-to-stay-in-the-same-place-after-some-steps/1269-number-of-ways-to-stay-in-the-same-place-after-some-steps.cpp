class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    vector<vector<int>>dp;
    
    int func(int index,int n,int steps){
        if(index < 0 || index >= n) return 0;
        if(steps == 0){
            if(index == 0) return 1;
            else return 0;
        }
        if(dp[index][steps] != -1) return dp[index][steps];
        ll ways = (ll)func(index,n,steps-1);
        ways %= M;
        ways += (ll)func(index+1,n,steps-1);
        ways %= M;
        ways += (ll)func(index-1,n,steps-1);
        ways %= M;
        return dp[index][steps] = (int)ways;
    }
    
    int numWays(int steps, int arrLen) {
        dp.clear();
        arrLen = min(arrLen, steps);
        dp = vector<vector<int>>(arrLen+1,vector<int>(steps+1,-1));
        int ans = func(0,arrLen,steps);
        return ans;
    }
};