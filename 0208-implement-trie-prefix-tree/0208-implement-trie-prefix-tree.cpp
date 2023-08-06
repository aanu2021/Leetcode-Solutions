struct Node{
   Node*links[26];
   bool endWord;
   Node(){
       endWord = false;
       for(int i=0;i<26;i++){
           links[i] = NULL;
       }
   }  
   bool containsKey(char ch){
       return (links[ch-'a'] != NULL);
   } 
   Node*get(char ch){
       return links[ch-'a'];
   } 
   void put(char ch,Node*node){
       links[ch-'a'] = node;
   } 
   void setEnd(){
       endWord = true;
   } 
   bool isEnd(){
       return endWord;
   } 
};

class Trie {
public:
    
    Node*root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node*node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node*node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};

