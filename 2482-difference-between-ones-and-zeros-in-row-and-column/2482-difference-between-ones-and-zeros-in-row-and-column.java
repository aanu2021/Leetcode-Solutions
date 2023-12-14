class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int oneRow[] = new int[m];
        int zeroRow[] = new int[m];
        int oneCol[] = new int[n];
        int zeroCol[] = new int[n];
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
        int answer[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                answer[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
            }
        }
        return answer;
    }
}