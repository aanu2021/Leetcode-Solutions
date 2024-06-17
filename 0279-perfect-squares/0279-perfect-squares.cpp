class Solution {
public:
    
    bool isPerfectSquare(int num){
        int val = sqrt(num);
        if(val*val == num) return true;
        else return false;
    }
    
    int numSquares(int n) {
        /*
           Lagrange's four square theorem.
           Any number is a summation of atmost 4 perfect squares
           N = 4^k (8m + 7)
        */
        if(isPerfectSquare(n)) return 1;
        while(n%4 == 0) n/=4;
        if(n%8 == 7) return 4;
        for(int i=1;i*i<=n;i++){
            int rem = n - (i*i);
            if(isPerfectSquare(rem)) return 2;
        }
        return 3;
    }
};