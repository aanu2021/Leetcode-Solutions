class Solution {
public:
    
    typedef long long ll;
    
    double myPow(double x, int nn) {
        
        if(nn==0) return 1.0;
        if(nn==1) return x;
        ll n = (ll)nn;
        double res = 1.0;
        if(n < 0){
            n = -1*n;
            x = 1.0/x;
        }
        while(n){
            if(n%2) res *= x;
            n /= 2;
            x *= x;
        }
        
        return res;
    }
};