class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       
        int n=prices.size();
        
        if(n<=1){
            return 0;
        }
        
        int oldbuy=-prices[0];
        int oldsold=0;
        
        for(int i=1;i<n;i++){
            
            int newbuy=oldsold-prices[i];
            int newsold=oldbuy+prices[i]-fee;
            
            newbuy=max(newbuy,oldbuy);
            newsold=max(newsold,oldsold);
            
            oldbuy=newbuy;
            oldsold=newsold;
            
        }
        
        return max(oldbuy,oldsold);
        
    }
};