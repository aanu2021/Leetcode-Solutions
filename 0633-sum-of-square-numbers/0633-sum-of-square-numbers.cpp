class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=c;a++){
            long b = c - (a*a);
            long sqrtb = (int)sqrt(b);
            if(sqrtb*sqrtb == b) return true;
        }
        return false;
    }
};