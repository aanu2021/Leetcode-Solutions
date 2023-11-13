class Solution {
    
    public boolean isSafe(char board[][], int row, int col, int n){
        for(int i=0;i<n;i++){
            if(board[row][i] == 'Q' || board[i][col] == 'Q') return false;
        }
        int r = row;
        int c = col;
        for(;r>=0 && c>=0;r--,c--){
            if(board[r][c] == 'Q') return false;
        }
        r = row;
        c = col;
        for(;r>=0 && c<n;r--,c++){
            if(board[r][c] == 'Q') return false;
        }
        r = row;
        c = col;
        for(;r<n && c>=0;r++,c--){
            if(board[r][c] == 'Q') return false;
        }
        r = row;
        c = col;
        for(;r<n && c<n;r++,c++){
            if(board[r][c] == 'Q') return false;
        }
        return true;
    }
    
    public void storeBoard(char board[][], List<List<String>>allBoards, int n){
        List<String>rowBoard = new ArrayList<>();
        for(int i=0;i<n;i++){
            String row = "";
            for(int j=0;j<n;j++){
                row += board[i][j];
            }
            rowBoard.add(row);
        }
        allBoards.add(rowBoard);
    }
    
    public void solve(char board[][], List<List<String>>allBoards, int row, int n){
        if(row == n){
            storeBoard(board,allBoards,n);
            return;
        }
        for(int col=0;col<n;col++){
            if(board[row][col] == '.'){
                if(isSafe(board,row,col,n) == true){
                    board[row][col] = 'Q';
                    solve(board,allBoards,row+1,n);
                    board[row][col] = '.';
                }
            }
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        char board[][] = new char[n][n];
        List<List<String>>allBoards = new ArrayList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) board[i][j] = '.';
        }
        solve(board,allBoards,0,n);
        return allBoards;
    }
}