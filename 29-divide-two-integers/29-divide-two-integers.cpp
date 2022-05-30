class Solution {
public:
    
    typedef long long ll;
    
    int divide(int dividend, int divisor) {
        
        ll res=(ll)dividend/(ll)divisor;
        
        if(res>INT_MAX){
            return INT_MAX;
        }
        
        if(res<INT_MIN){
            return INT_MIN;
        }
        
        return res;
        
    }
};