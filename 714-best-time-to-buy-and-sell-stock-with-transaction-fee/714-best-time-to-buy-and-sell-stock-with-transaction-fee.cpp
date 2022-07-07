class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        
        int oldbuy=-prices[0];
        int oldsold=0;
        
        for(int i=1;i<n;++i){
            
            int newbuy,newsold;
            
            newbuy=max(oldsold-prices[i],oldbuy);
            
            newsold=max(oldsold,oldbuy+prices[i]-fee);
            
            oldbuy=newbuy;
            
            oldsold=newsold;
            
        }
        
        return max(oldbuy,oldsold);
        
    }
};