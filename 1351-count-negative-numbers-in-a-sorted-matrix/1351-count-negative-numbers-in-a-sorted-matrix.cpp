class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int ans = 0;
        
        int j = n-1;
        
        for(int i=0;i<m;i++){
            while(j>=0 && grid[i][j] < 0){
                j--;
            }
            ans += (n-j-1);
        }
        
        return ans;
        
    }
};