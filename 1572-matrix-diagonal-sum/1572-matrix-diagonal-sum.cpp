class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += mat[i][i];
            totalSum += mat[i][n-i-1];
        }
        if(n%2) totalSum -= mat[n/2][n/2];
        return totalSum;
    }
};