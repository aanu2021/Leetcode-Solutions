class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        int mini=INT_MAX;
        
        int total=0;
        
        for(int i=0;i<n;i++){
            
            if(prices[i]<mini){
                mini=prices[i];
            }
            
            else if(prices[i]-mini>total){
                total=prices[i]-mini;
            }
            
        }
        
        return total;
        
    }
};