class Solution {
public:
    
    vector<vector<string>>result;
    
    void backtrack(vector<vector<char>>&board,int r,vector<int>&flag_col,vector<int>&flag_45,vector<int>&flag_135,int n){
        
        if(r==board.size()){
            
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
            
            if(flag_col[c] && flag_45[r+c] && flag_135[n-1-r+c]){
                
                board[r][c]='Q';
                flag_col[c]=flag_45[r+c]=flag_135[n-1-r+c]=0;

                backtrack(board,r+1,flag_col,flag_45,flag_135,n); 
                
                flag_col[c]=flag_45[r+c]=flag_135[n-1-r+c]=1;
                board[r][c]='.';
                
                
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>>board(n,vector<char>(n,'.'));
        
        vector<int>flag_col(n,1);
        
        vector<int>flag_45(2*n-1,1);
        
        vector<int>flag_135(2*n-1,1);
        
        backtrack(board,0,flag_col,flag_45,flag_135,n);
        
        return result;
        
    }
};