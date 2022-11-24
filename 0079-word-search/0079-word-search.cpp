class Solution {
public:
    
    /* T.C : O(M*N*Len(word)*4)
       S.C : O(1) */
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool dfs(vector<vector<char>>&board,string &word,int i,int j,int k){
        if(k==word.length()) return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool flag = false;
        for(int dir=0;dir<4;dir++){
            flag|=dfs(board,word,i+dx[dir],j+dy[dir],k+1);
        }
        if(flag) return true;
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j] && dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};