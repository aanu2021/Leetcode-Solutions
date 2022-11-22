class Solution {
public:
    int numSquares2(int n) {
       vector<int>dp(n+1,1e9);
       dp[0] = 0;
       dp[1] = 1;
       for(int i=2;i<=n;i++){
           for(int j=1;j*j<=i;j++){
               dp[i] = min(dp[i],1 + dp[i-j*j]);
           }
       } 
       return dp[n]; 
    }
    
    bool isSquare(int n){
        int ele = sqrt(n);
        if(ele*ele==n) return true;
        else return false;
    }
    
    int numSquares(int n) {
        
       // Lagrange's Four Square Theorem 
        
       // Every number can be represented as the summation of atmost 4 integers 
        
        // NUM = 4^k * (8*m + 7)
        
        // When the Given number is itself a square.
        
        if(isSquare(n)) return 1;
        
        while(n && n%4==0){
            n/=4;
        }
        
        if(n%8==7) return 4;
        
        // Check for 2 , 3
        
        for(int i=1;i*i<=n;i++){
            int rem = n - (i*i);
            if(isSquare(rem)) return 2;
        }
        
        return 3;
        
    }
};