class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       
        if(n==0) return 1;
        if(n==1) return 10;
        
        vector<int>dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 9;
        
        int prod = 1;
        int cnt = 9;
        
        for(int i=2;i<=n;i++){
            
            prod*=cnt;
            cnt--;
            
            dp[i] = 9*prod;
            
        }
        
        int sum = accumulate(dp.begin(),dp.end(),0);
        
        return sum;
        
    }
};