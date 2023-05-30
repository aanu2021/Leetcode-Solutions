//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool dfs(vector<vector<char>>&board,int i,int j,string &word,int k){
        
        if(k==word.length()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] != word[k]) return false;
       
        char temp = board[i][j];
        board[i][j] = '*';
        
        for(int dir=0;dir<4;dir++){
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            bool flag = dfs(board,ni,nj,word,k+1);
            if(flag){
                return true;
            }
        }
        
        board[i][j] = temp;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,i,j,word,0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends