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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return grid;
    }
};