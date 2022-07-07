class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        
        int mini=prices[0];
        int maxi=prices[n-1];
        
        for(int i=0;i<n;i++){
            
            mini=min(mini,prices[i]);
            
            prefix[i]=max((i-1>=0 ? prefix[i-1] : 0),(prices[i]-mini));
            
        }
        
        for(int i=n-1;i>=0;i--){
            
            maxi=max(maxi,prices[i]);
            
            suffix[i]=max((i+1<n ? suffix[i+1] : 0),(maxi-prices[i]));
            
        }
        
        int ans=prefix[n-1];
        
        for(int i=0;i<n-1;++i){
            ans=max(ans,prefix[i]+suffix[i+1]);
        }
        
        return ans;
        
    }
};