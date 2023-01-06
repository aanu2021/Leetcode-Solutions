class Solution {
public:
    
    int maxIceCream2(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        for(int i=0;i<n;i++){
            coins-=costs[i];
            if(coins < 0) return i;
        }
        return n;
    }
    
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxCost = *max_element(costs.begin(),costs.end());
        vector<int>freq(maxCost+1,0);
        for(int &ele:costs){
            freq[ele]++;
        }
        int pick = 0;
        for(int i=1;i<=maxCost;i++){
            int curr = coins / i;
            curr = min(curr,freq[i]);
            pick += curr;
            coins -= (curr*i);
        }
        return pick;
    }
    
};