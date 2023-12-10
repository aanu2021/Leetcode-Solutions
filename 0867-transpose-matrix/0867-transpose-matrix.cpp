class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>answer(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer[j][i] = grid[i][j];
            }
        }
        return answer;
    }
};

// 1 2 3
// 4 5 6    