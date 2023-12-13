class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    row[i]++; col[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(row[i] == 1 && col[j] == 1) cnt++;
                }
            }
        }
        return cnt;
    }
};