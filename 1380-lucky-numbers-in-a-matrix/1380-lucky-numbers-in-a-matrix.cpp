class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int rowMinMax = INT_MIN;
        int colMaxMin = INT_MAX;
        
        for(int i=0;i<m;i++){
            int rowMin = INT_MAX;
            for(int j=0;j<n;j++) rowMin = min(rowMin, grid[i][j]);
            rowMinMax = max(rowMinMax, rowMin);
        }
        
        for(int j=0;j<n;j++){
            int colMax = INT_MIN;
            for(int i=0;i<m;i++) colMax = max(colMax, grid[i][j]);
            colMaxMin = min(colMaxMin, colMax);
        }
        
        if(rowMinMax == colMaxMin) return {rowMinMax};
        else return {};
    }
};

/*

B    X

Y    A

X > A    X < B
Y < A    Y > B

X > Y    X < Y

X > Y and X < Y can't be true at the same time.
There can be atmost one lucky number in the matrix.   

*/
