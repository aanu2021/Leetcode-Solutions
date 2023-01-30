class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int x = 0 , y = 1, z = 1;
        for(int i=3;i<=n;i++){
            int new_z = x+y+z;
            x = y;
            y = z;
            z = new_z;
        }
        return z;
    }
};