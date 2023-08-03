class Solution {
public:
    
    vector<vector<string>>answer;
    
    bool isPossible(vector<vector<char>>&board,int row,int col,vector<vector<int>>&queenCells){
        
        for(int i=0;i<queenCells.size();++i){
            int nrow = queenCells[i][0];
            int ncol = queenCells[i][1];
            // Same row and column check
            if((row == nrow) || (col == ncol)){
                return false;
            }
            // Diagonal Check
            if((row-col) == (nrow-ncol)){
                return false;
            }
            if((row+col) == (nrow+ncol)){
                return false;
            }
        }
        
        return true;
        
    }
    
    void recursion(vector<vector<char>>&board,int row,int n,vector<vector<int>>&queenCells){
        
        if(row == n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string curr = "";
                for(int j=0;j<n;j++){
                    curr += board[i][j];
                }
                temp.push_back(curr);
            }
            answer.push_back(temp);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(board[row][col] == '.'){
                if(isPossible(board,row,col,queenCells)){
                    board[row][col] = 'Q';
                    queenCells.push_back({row,col});
                    recursion(board,row+1,n,queenCells);
                    queenCells.pop_back();
                    board[row][col] = '.';
                }
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>queenCells;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        recursion(board,0,n,queenCells);
        return answer;
    }
};