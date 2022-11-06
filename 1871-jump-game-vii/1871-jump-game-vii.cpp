class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]=='1') return false;
        vector<int>dp(n,0);
        dp[0]=1;
        int prev = 0;
        for(int i=1;i<n;i++){
            if(i>=minJump){
                prev+=dp[i-minJump];
            }
            if(i>maxJump){
                prev-=dp[i-maxJump-1];
            }
            if(s[i]=='0' && prev>0){
                dp[i] = 1;
            }
        }
        return dp[n-1];
    }
};