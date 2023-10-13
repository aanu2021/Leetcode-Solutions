class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int minCost = INT_MAX;
        int next = 0;
        int next_next = 0;
        for(int i=n-1;i>=0;i--){
            int currCost = cost[i] + min(next, next_next);
            if(i==0 || i==1) minCost = min(minCost, currCost);
            next_next = next;
            next = currCost;
        }
        return minCost;
    }
};