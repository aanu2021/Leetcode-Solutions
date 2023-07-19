class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size();
        int m = worker.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i] = {difficulty[i], profit[i]};
        }
        
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<n;i++){
            difficulty[i] = vec[i].first;
            profit[i] = vec[i].second;
        }
        
        for(int i=1;i<n;i++){
            profit[i] = max(profit[i-1], profit[i]);
        }
        
        int totalProfit = 0;
        
        for(int i=0;i<m;i++){
            int work = worker[i];
            int idx = upper_bound(difficulty.begin(),difficulty.end(),work) - difficulty.begin();
            idx--;
            if(idx >= 0){
                totalProfit += profit[idx];
            }
        }
        
        return totalProfit;
        
    }
};

// 2  4  6  8  10
// 10 20 30 40 50
    
// 4  5  6  7
    
// 20 + 20 + 30 + 30    