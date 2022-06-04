class Solution {
public:
    
    vector<vector<string>>result;
    
    bool isValid(vector<vector<char>>board,int r,int c,vector<vector<int>>queens){
        
        for(int i=0;i<queens.size();i++){
            
            int dx=abs(queens[i][0]-r);
            int dy=abs(queens[i][1]-c);
            
            if(dx==0 || dy==0 || dx==dy){
                return false;
            }
            
        }
        
        return true;
        
    }
    
    void backtrack(vector<vector<char>>board,int r,vector<vector<int>>queens){
        
        if(queens.size()==board.size()){
            
            vector<string>vec;
            
            for(int i=0;i<board.size();i++){
                
                string str="";
                
                for(int j=0;j<board.size();j++){
                    
                    str+=board[i][j];
                    
                }
                
                vec.push_back(str);
                
            }
            
            result.push_back(vec);
            
            return;
        }
        
        
        for(int c=0;c<board.size();c++){
            
            if(board[r][c]=='.'){
                
                if(isValid(board,r,c,queens)==true){
                    
                    board[r][c]='Q';
                    queens.push_back({r,c});
                    
                    backtrack(board,r+1,queens);
                    
                    queens.pop_back();
                    board[r][c]='.';
                    
                }
                
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>>board(n,vector<char>(n,'.'));
        
        vector<vector<int>>queens;
        
        backtrack(board,0,queens);
        
        return result;
        
    }
};