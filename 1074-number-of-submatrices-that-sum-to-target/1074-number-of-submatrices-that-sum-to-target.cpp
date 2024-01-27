class Solution {
public:
    
    int calculateSum(vector<vector<int>>&grid, int row, int c1, int c2)
    {
        return (grid[row][c2] - (c1 > 0 ? grid[row][c1-1] : 0));
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j] += grid[i][j-1];
            }
        }
        
        int answer = 0;
        for(int c1=0;c1<n;c1++){
            for(int c2=c1;c2<n;c2++){
                unordered_map<int,int>freq;
                freq[0] = 1;
                int currSum = 0;
                for(int row=0;row<m;row++){
                    currSum += calculateSum(grid,row,c1,c2);
                    answer += freq[currSum-target];
                    freq[currSum]++;
                }
            }
        }
        return answer;
    }
};

   