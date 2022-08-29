struct Node{
    
  Node*links[26];
  bool endWord=false;  
    
  bool containsKey(char ch){
      
      return (links[ch-'a']!=NULL);
      
  }  
    
  Node*get(char ch){
      
       return links[ch-'a'];
      
  }
    
  void put(char ch,Node*node){
      
      links[ch-'a']=node;
      
  }  
    
  void setWord(){
      
      endWord=true;
      
  }  
    
  bool isEnd(){
      
      return endWord;
      
  }  
    
};

class Trie {
    
    Node*root;
    
public:
    Trie() {
        
        root=new Node();
        
    }
    
    void insert(string word) {
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            
            node=node->get(word[i]);
            
        }
        
        node->setWord();
        
    }
    
    bool search(string word) {
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                return false;
            }
            
            node=node->get(word[i]);
            
        }
        
        return node->endWord;
        
    }
    
    bool startsWith(string word) {
        
        Node*node=root;
        
        for(int i=0;i<word.length();++i){
            
            if(!node->containsKey(word[i])){
                return false;
            }
            
            node=node->get(word[i]);
            
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */