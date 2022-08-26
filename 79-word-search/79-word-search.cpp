class Solution {
public:
    
    bool func(vector<vector<char>>&board,int i,int j,string &word,int k){
        
        if(k==word.length()){
            return true;
        }
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        
        char temp=board[i][j];
        
        board[i][j]='*';
        
        bool ans=func(board,i+1,j,word,k+1) || func(board,i-1,j,word,k+1) || func(board,i,j+1,word,k+1) || func(board,i,j-1,word,k+1);
        
        board[i][j]=temp;
        
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;++i){
            
            for(int j=0;j<n;++j){
                
                if(board[i][j]==word[0] && func(board,i,j,word,0)){
                    
                    return true;
                    
                }
                
            }
            
        }
        
        return false;
        
    }
};