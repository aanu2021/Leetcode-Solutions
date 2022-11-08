class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       
        if(n==0) return 1;
        if(n==1) return 10;
        
        vector<int>dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 9;
        
        for(int i=2;i<=n;i++){
            
            int cnt = 9;
            
            int prod = 9;
            
            for(int j=1;j<i;j++){
                prod*=cnt;
                cnt--;
            }
            
            dp[i] = prod;
            
        }
        
        int sum = accumulate(dp.begin(),dp.end(),0);
        
        return sum;
        
    }
};