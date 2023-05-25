class Solution {
public:
    double new21Game(int n, int k, int w) {
        
        if(k==0 || n >= k+w) return 1.0;
        
        double dp[n+1];
        memset(dp,0.0,sizeof(dp));
        dp[0] = 1.0;
        
        double Wsum = 1.0;
        for(int i=1;i<=n;i++){
            dp[i] = Wsum/w;
            if(i < k) Wsum += dp[i];
            if(i - w >= 0 && i - w < k) Wsum -= dp[i-w];
        }
        
        double sum = 0.0;
        for(int i=k;i<=n;i++){
            sum += dp[i];
        }
        return sum;
        
    }
};

/*

a0 a1 a2 a3 a4 a5

k = 5
 
i

j    

i-j >= 0
    
i = 6
    
j = 1,2,3,4,5,6,7,8,9,10
    
k = 5
    
n = 13
   
Left  Boundary : max(0,i-maxPts)
   
Right Boundary : min(i-1,k-1)
    
[Left, Right]

dp[i] = ( dp[Left] + dp[Left+1] + dp[Left+2] + ... + dp[Right-1] + dp[Right] ) / maxPts


0 1 2 3 4 5 6 7 8    
    '   '   .
*/    
