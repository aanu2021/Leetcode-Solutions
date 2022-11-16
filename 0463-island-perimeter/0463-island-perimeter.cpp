class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                ans+=4;
                for(int dir=0;dir<4;dir++){
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};