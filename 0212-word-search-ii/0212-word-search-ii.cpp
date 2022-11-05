/*

Time Complexity  : O(Len(words)*Size of words[i])
Space Complexity : O(1)

*/

struct Node{
  
    Node*links[26];
    int endWord;
    string word;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    Node*get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch,Node*node){
        links[ch-'a'] = node;
    }
    
};

class Solution {
public:
    
    vector<string>ans;
    
    Node*root = new Node();
    
    void insert(string &word){
        
        Node*node = root;
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        
        node->endWord++;
        node->word=word;
        
    }
    
    void func(vector<vector<char>>&board,int i,int j,Node*curr){
        
        int m = board.size();
        int n = board[0].size();
        
        if(board[i][j]=='*') return;
        
        if(!curr->containsKey(board[i][j])) return;
        
        curr=curr->get(board[i][j]);
        
        if(curr->endWord>0){
            curr->endWord--;
            ans.push_back(curr->word);
        }
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        if(i>0){
            func(board,i-1,j,curr);
        }
        if(j>0){
            func(board,i,j-1,curr);
        }
        if(i<m-1){
            func(board,i+1,j,curr);
        }
        if(j<n-1){
            func(board,i,j+1,curr);
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
                func(board,i,j,curr);
            }
        }
        
        return ans;
        
    }
};