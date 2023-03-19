struct Node{
   
    Node*links[26];
    bool endWord;
    
    Node(){
        for(int i=0;i<26;i++){
            links[i] = NULL;
        }
        endWord = false;
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
    void setEndWord(){
        endWord = true;
    }
    bool isEndWord(){
        return endWord;
    }
    
};

class WordDictionary {
public:
    
    Node * root;
    
    WordDictionary() {
        root = new Node();
    }
    
    bool canFind(int i,string &word,Node*node){
        if(i == word.length()){
            return node->isEndWord();
        }
        if(word[i]=='.'){
            bool flag = false;
            for(int j=0;j<26;j++){
                char ch = (char)(j+'a');
                if(node->containsKey(ch)){
                    flag |= canFind(i+1,word,node->get(ch));
                    if(flag){
                        break;
                    }
                }
            }
            return flag;
        }
        else{
            if(!node->containsKey(word[i])){
                return false;
            }
            else{
                return canFind(i+1,word,node->get(word[i]));
            }
        }
    }
    
    void addWord(string word) {
        Node * node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEndWord();
    }
    
    bool search(string word) {
        Node * node = root;
        return canFind(0,word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */