class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int mini=prices[0];
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            prefix[i]=max(prefix[i-1],prices[i]-mini);
        }
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i]);
            suffix[i]=max(suffix[i+1],maxi-prices[i]);
        }
        int max_profit = prefix[n-1];
        for(int i=1;i<n;i++){
            max_profit=max(max_profit,prefix[i-1]+suffix[i]);
        }
        return max_profit;
    }
};