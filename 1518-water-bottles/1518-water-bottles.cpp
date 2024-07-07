class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=0;
        int w=numBottles;
        int m=numExchange;
        sum=w;
        while(w>=m){
            sum+=(w/m);
            w=(w/m)+(w%m);
        }
        return sum;
    }
};