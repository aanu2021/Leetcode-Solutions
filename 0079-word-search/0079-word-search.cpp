class Solution {
public:
    
    /*
    
    T.C : O(M*N*4^L) --> [ 4^L <= (M*N) ]
    S.C : O(1)
    
    */
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool func(vector<vector<char>>&board,string &word,int i,int j,int k,int m,int n){
        
        if(k == word.length()) return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
        bool flag = false;
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(func(board,word,ni,nj,k+1,m,n)){
                flag = true;
                break;
            }
        }
        if(flag){
            return true;
        }
        board[i][j] = temp;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && func(board,word,i,j,0,m,n))
                {
                    return true;
                }
            }
        }
        return false;
    }
};