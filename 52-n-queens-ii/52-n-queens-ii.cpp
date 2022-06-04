class Solution {
public:
    
    int ans=0;
    
    void backtrack(vector<vector<char>>&board,int r,vector<int>&flag_col,vector<int>&flag_45,vector<int>&flag_135,int n){
        
        if(r==board.size()){
            ans++;
            return;
        }
        
        for(int c=0;c<n;c++){
            
            if(flag_col[c] && flag_45[r+c] && flag_135[n-1-r+c]){
                
                board[r][c]='Q';
                flag_col[c]=flag_45[r+c]=flag_135[n-1-r+c]=0;
                
                backtrack(board,r+1,flag_col,flag_45,flag_135,n);
                
                board[r][c]='.';
                flag_col[c]=flag_45[r+c]=flag_135[n-1-r+c]=1;
                
            }
            
        }
        
    }
    
    int totalNQueens(int n) {
        
        vector<vector<char>>board(n,vector<char>(n,'.'));
        
        vector<int>flag_col(n,1);
        vector<int>flag_45(2*n-1,1);
        vector<int>flag_135(2*n-1,1);
        
        backtrack(board,0,flag_col,flag_45,flag_135,n);
        
        return ans;
        
    }
};