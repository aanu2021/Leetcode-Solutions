class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        int oldbuy = 0, oldsold = 0;
        
        for(int i=n-1;i>=0;i--){
            
            int newbuy = max(oldbuy, -prices[i] + oldsold);
            int newsold = max(oldsold, prices[i] - fee + oldbuy);
            
            oldbuy = newbuy;
            oldsold = newsold;
            
        }
        
        return oldbuy;
        
    }
};