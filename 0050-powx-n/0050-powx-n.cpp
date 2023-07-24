class Solution {
public:
    
    typedef long long ll;
    
    double myPow(double x, int nn) {
        
        ll n = (ll)nn;
        
        if(n==0) return 1.0;
        if(n==1) return x;
        
        double result = 1.0;
        if(n < 0){
            n *= -1;
            x = 1.0/x;
        }
        
        while(n){
            if(n%2) result *= x;
            n /= 2;
            x *= x;
        }
        
        return result;
        
    }
};