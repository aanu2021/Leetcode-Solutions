class Solution {
public:
    
    struct Node{
        
       Node*links[26];
       int endword;
       string eword; 
        
       bool containsKey(char ch){
           
           return (links[ch-'a']!=NULL);
           
       } 
        
       Node*get(char ch){
           
           return links[ch-'a'];
           
       } 
        
       void put(char ch,Node*node){
           
           links[ch-'a']=node;
           
       } 
        
    };
    
    Node*root=new Node();
    
    vector<string>ans;
    
    void insert(string &word){
        
        Node*curr=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            
            curr=curr->get(word[i]);
            
        }
        
        curr->endword++;
        curr->eword=word;
        
    }
    
    void func(vector<vector<char>>&board,int i,int j,Node*curr){
        
        int m=board.size();
        int n=board[0].size();
        
        if(board[i][j]=='*'){
            return;
        }
        
        if(!curr->containsKey(board[i][j])){
            return;
        }
        
        curr=curr->get(board[i][j]);
        
        if(curr->endword>0){
            
            curr->endword--;
            
            ans.push_back(curr->eword);
            
        }
        
        char temp=board[i][j];
        
        board[i][j]='*';
        
        if(i>0)
            func(board,i-1,j,curr);
        
        if(i<m-1)
            func(board,i+1,j,curr);
        
        if(j>0)
            func(board,i,j-1,curr);
        
        if(j<n-1)
            func(board,i,j+1,curr);
        
        board[i][j]=temp;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(string str:words){
            insert(str);
        }
        
        Node*curr=root;
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                func(board,i,j,curr);
            }
        }
        
        return ans;
        
    }
};