class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        if(n<=1){
            return 0;
        }
        
        vector<int>inhand(n,0);
        vector<int>sold(n,0);
        vector<int>nostock(n,0);
        
        inhand[0]=-prices[0];
        
        for(int i=1;i<n;i++){
            
            inhand[i]=max(inhand[i-1],nostock[i-1]-prices[i]);
            
            sold[i]=max(sold[i-1],inhand[i-1]+prices[i]);
            
            nostock[i]=max(nostock[i-1],sold[i-1]);
            
        }
        
        return max(inhand[n-1],sold[n-1]);
        
    }
};