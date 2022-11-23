class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>S;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                string row_s = to_string(i) + "row" + to_string(board[i][j]-'0');
                string col_s = to_string(j) + "col" + to_string(board[i][j]-'0');
                string box_s = to_string(((i/3)*3) + (j/3)) + "box" + to_string(board[i][j]-'0');
                if(S.find(row_s)!=S.end()) return false;
                if(S.find(col_s)!=S.end()) return false;
                if(S.find(box_s)!=S.end()) return false;
                S.insert(row_s);
                S.insert(col_s);
                S.insert(box_s);
            }
        }
        return true;
    }
};