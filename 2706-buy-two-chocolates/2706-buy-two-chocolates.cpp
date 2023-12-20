class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int fmin = 100000000, smin = 100000000;
        for(int i=0;i<n;i++){
            if(prices[i] < fmin){
                smin = fmin;
                fmin = prices[i];
            }
            else if(prices[i] < smin){
                smin = prices[i];
            }
        }
        int totalSum = fmin + smin;
        if(money < totalSum) return money;
        else return (money - totalSum);
    }
};