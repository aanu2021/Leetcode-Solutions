struct Node{
  
    Node*links[26];
    int endWord;
    string eW;
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    Node*get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node*node){
        links[ch-'a'] = node;
    }
    
    void setWord(){
        endWord++;
    }
    
};

class Solution {
public:
    
    Node*root = new Node();
    
    void insert(string &word){
        
        Node*node = root;
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        
        node->setWord();
        node->eW = word;
        
    }
    
    vector<string>ans;
    
    void dfs(vector<vector<char>>&board,int i,int j,Node*curr){
        
        int m = board.size();
        int n = board[0].size();
        
        if(board[i][j]=='*') return;
        if(!curr->containsKey(board[i][j])) return;
        curr = curr->get(board[i][j]);
        
        if(curr->endWord>0){
            ans.push_back(curr->eW);
            curr->endWord--;
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        if(i>0){
            dfs(board,i-1,j,curr);
        }
        if(i<m-1){
            dfs(board,i+1,j,curr);
        }
        if(j>0){
            dfs(board,i,j-1,curr);
        }
        if(j<n-1){
            dfs(board,i,j+1,curr);
        }
        
        board[i][j] = temp;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(string &str:words){
            insert(str);
        }
        
        Node*curr = root;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,curr);
            }
        }
        
        return ans;
        
    }
};