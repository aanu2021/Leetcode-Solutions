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
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            
            node=node->get(word[i]);
            
        }
        
        node->endword++;
        
        node->eword=word;
        
    }
    
    void func(vector<vector<char>>&board,int i,int j,int m,int n,Node*curr){
        
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
            func(board,i-1,j,m,n,curr);
        
        if(i<m-1)
            func(board,i+1,j,m,n,curr);
        
        if(j>0)
            func(board,i,j-1,m,n,curr);
        
        if(j<n-1)
            func(board,i,j+1,m,n,curr);
        
        board[i][j]=temp;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int m=board.size();
        int n=board[0].size();
        
        for(string str:words){
            insert(str);
        }
        
        Node*curr=root;
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                func(board,i,j,m,n,curr);
            }
        }
        
        return ans;
        
    }
};