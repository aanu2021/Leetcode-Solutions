class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>zeroRow(m,0);
        vector<int>oneRow(m,0);
        vector<int>zeroCol(n,0);
        vector<int>oneCol(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    oneRow[i]++;
                    oneCol[j]++;
                }
                else{
                    zeroRow[i]++;
                    zeroCol[j]++;
                }
            }
        }
        vector<vector<int>>answer(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return answer;
    }
};