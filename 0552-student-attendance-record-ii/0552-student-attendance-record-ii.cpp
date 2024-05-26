class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int dp[100005][4][2][4];
    
    int func(int i, int cons, int absent_cnt, int prev, int n){
        if(cons > 2) return 0;
        if(absent_cnt > 1) return 0;
        if(i == n) return 1;
        if(dp[i][cons][absent_cnt][prev] != -1) return dp[i][cons][absent_cnt][prev];
        ll ways = 0LL;
        // Present
        ways += (ll)func(i+1, 0, absent_cnt, 0, n);
        ways %= M;
        // Absent
        ways += (ll)func(i+1, 0, absent_cnt+1, 1, n);
        ways %= M;
        // Late   
        ways += (ll)func(i+1, cons + 1, absent_cnt, 2, n);
        ways %= M;
        return dp[i][cons][absent_cnt][prev] = (int)ways;
    }
    
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        // idx, cons, absent_cnt, prev
        int answer = func(0, 0, 0, 3, n);
        return answer;
    }
};


