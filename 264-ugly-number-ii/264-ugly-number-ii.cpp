class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>dp(n,0);
        
        // Trivial Case.......
        
        dp[0]=1;
        
        // Here the prime factors should be limited within 2, 3, 5
        
        int mul_2=2,mul_3=3,mul_5=5;
        
        int i2=0,i3=0,i5=0;
        
        for(int i=1;i<n;i++){
            
            int next_ugly=min(mul_2,min(mul_3,mul_5));
            
            dp[i]=next_ugly;
            
            if(mul_2==next_ugly){
                
                i2++;
                
                mul_2=dp[i2]*2;
                
            }
            
            if(mul_3==next_ugly){
                
                i3++;
                
                mul_3=dp[i3]*3;
                
            }
            
            if(mul_5==next_ugly){
                
                i5++;
                
                mul_5=dp[i5]*5;
                
            }
            
        }
        
        return dp[n-1];
        
    }
};