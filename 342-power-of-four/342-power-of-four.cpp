class Solution {
public:
    bool isPowerOfFour(int nn) {
        
        if(nn<=0){
            return false;
        }
        
        long long n=nn;
        
        if((n&(n-1))){
            return false;
        }
        
        return !(n&(0xAAAAAAAA));
        
    }
};