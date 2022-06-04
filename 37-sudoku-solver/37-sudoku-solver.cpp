class Solution {
public:
    
    bool isValid(vector<vector<char>>&board,int i,int j,char val){
        
        for(int r=0;r<9;r++){
            if(board[r][j]==val){
                return false;
            }
        }
        
        for(int c=0;c<9;c++){
            if(board[i][c]==val){
                return false;
            }
        }
        
        int smi=(i/3)*3;
        int smj=(j/3)*3;
        
       for(int r=0;r<3;r++){
           for(int c=0;c<3;c++){
               if(board[r+smi][c+smj]==val){
                   return false;
               }
           }
       }
        
        return true;
        
    }
    
    bool func(vector<vector<char>>&board){
        
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.'){
                    
                    for(char num='1';num<='9';num++){
                        
                        if(isValid(board,i,j,num)==true){
                            
                            board[i][j]=num;
                            
                            if(func(board)==true){
                                return true;
                            }
                            
                            board[i][j]='.';
                            
                        }
                        
                    }
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        func(board);
        
    }
};