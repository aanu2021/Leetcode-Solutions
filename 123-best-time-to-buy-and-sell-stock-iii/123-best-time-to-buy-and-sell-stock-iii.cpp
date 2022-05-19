class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        if(n==1){
            return 0;
        }
        
        if(n==2){
            return max(0,prices[1]-prices[0]);
        }
        
        int maxval=0;
        
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        
        prefix[0]=0;
        
        int mini=prices[0];
        
        for(int i=1;i<n;i++){
            
            if(prices[i]<mini){
                mini=prices[i];
            }
            
            prefix[i]=max(prefix[i-1],(prices[i]-mini));
            
        }
        
        suffix[n-1]=0;
        
        int maxi=prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            
            if(prices[i]>maxi){
                maxi=prices[i];
            }
            
            suffix[i]=max(suffix[i+1],(maxi-prices[i]));
            
        }
        
        maxval=max(prefix[n-1],suffix[0]);
        
        for(int i=0;i<n-1;i++){
            maxval=max(maxval,prefix[i]+suffix[i+1]);
        }
        
        return maxval;
        
    }
};