class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>answer;
        vector<int>rowMin(m);
        vector<int>colMax(n);
        
        for(int i=0;i<m;i++){
            int mini = INT_MAX;
            for(int j=0;j<n;j++) mini = min(mini, grid[i][j]);
            rowMin[i] = mini;
        }
        
        for(int j=0;j<n;j++){
            int maxi = INT_MIN;
            for(int i=0;i<m;i++) maxi = max(maxi, grid[i][j]);
            colMax[j] = maxi;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowMin[i] == grid[i][j] && colMax[j] == grid[i][j]) answer.push_back(grid[i][j]);
            }
        }
        
        return answer;
    }
};