class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[2] < y[2];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        n/=2;
        for(int i=0;i<2*n;i++){
            costs[i].push_back(costs[i][0]-costs[i][1]);
        }
        sort(costs.begin(),costs.end(),comp);
        int totalCost = 0;
        for(int i=0;i<n;i++){
            totalCost += costs[i][0];
        }
        for(int i=2*n-1;i>=n;i--){
            totalCost += costs[i][1];
        }
        return totalCost;
    }
};