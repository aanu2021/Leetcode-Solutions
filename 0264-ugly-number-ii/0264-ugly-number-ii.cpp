class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p2 = 0,p3 = 0,p5 = 0;
        for(int i=1;i<n;i++){
            int mul_2 = 2*dp[p2];
            int mul_3 = 3*dp[p3];
            int mul_5 = 5*dp[p5];
            int next_mul = min({mul_2,mul_3,mul_5});
            if(next_mul==mul_2){
                p2++;
            }
            if(next_mul==mul_3){
                p3++;
            }
            if(next_mul==mul_5){
                p5++;
            }
            dp[i] = next_mul;
        }
        return dp[n-1];
    }
};