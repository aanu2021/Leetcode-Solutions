class Solution {
public:
    
    int gcd(int x,int y){
        if(y==0) return x;
        if(x==0) return y;
        if(x > y){
            return gcd(x%y,y);
        }
        else{
            return gcd(x,y%x);
        }
    }
    
    bool canMeasureWater(int x, int y, int z) {
        if(z > x+y) return false;
        int g = gcd(x,y);
        if(z%g == 0) return true;
        else return false;
    }
};