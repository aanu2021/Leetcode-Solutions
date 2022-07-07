class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // State Machine Format
        
        int n=prices.size();
        
        vector<int>inhand(n);
        
        vector<int>nostock(n);
        
        vector<int>sold(n);
        
        
        inhand[0]=-prices[0];
        
        nostock[0]=0;
        
        sold[0]=0;
        
        
        for(int i=1;i<n;++i){
            
            sold[i]=max(sold[i-1],inhand[i-1]+prices[i]);
            
            nostock[i]=max(nostock[i-1],sold[i-1]);
            
            inhand[i]=max(inhand[i-1],nostock[i-1]-prices[i]);
            
        }
        
        return max(nostock[n-1],sold[n-1]);
        
    }
};